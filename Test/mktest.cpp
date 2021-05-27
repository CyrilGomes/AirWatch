#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;
using std::filesystem::directory_iterator;

// https://helloacm.com/how-to-split-a-string-in-c/
vector<string> split(const string &text)
{
    string tmp;
    vector<string> stk;
    stringstream ss(text);
    while (getline(ss, tmp, ' '))
    {
        stk.push_back(tmp);
    }
    return stk;
}

// trim from end (in place)
// From StackOverflow: https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace)))
                .base(),
            s.end());
}

bool checkFiles(const string &filename1, const string &filename2)
{
    ifstream file1(filename1, ios::in);
    string str1(std::istreambuf_iterator<char>{file1}, {});
    file1.close();

    ifstream file2(filename2, ios::in);
    string str2(std::istreambuf_iterator<char>{file2}, {});
    file2.close();

    rtrim(str1); rtrim(str2);
    //cout << "STR1: " << endl << str1 + "\n" + "STR2: " << endl << str2 << endl;

    return str1 == str2;
}

vector<filesystem::path> getFilesInDirectory(string directoryName)
{
    vector<filesystem::path> fileList;
    for (const auto &file : directory_iterator("./" + directoryName))
    {
        if (!is_directory(file))
        {
            fileList.push_back(file.path());
        }
    }
    return fileList;
}

int main()
{
    int cptPassed = 0;
    int cptFailed = 0;
    string separator = "-----------------------------------------------------------";

    for (const auto &file : directory_iterator("./"))
    {
        string directoryName = file.path().filename().string();
        filesystem::path path = file.path();
        if (is_directory(file) && directoryName.find("Test") != string::npos)
        {
            system(("mkdir -p ./" + directoryName + "/Dataset/Local").c_str());
            system(("cp ./BaseLocalData/individuals.csv ./" + directoryName + "/Dataset/Local/individuals.csv").c_str());
            system(("cp ./BaseLocalData/logins.csv ./" + directoryName + "/Dataset/Local/logins.csv").c_str());

            vector<filesystem::path> fileList = getFilesInDirectory(directoryName);
            string execCmd = "";
            bool takeInput = false;
            bool compareOutput = false;
            bool compareError = false;
            for (const auto &filePath : fileList) {
                string fileName = filePath.filename().string();
                if (fileName == "description") {
                    cout << endl;
                    cout << separator << endl;
                    cout << "| TEST ID : " << directoryName << endl;
                    cout << separator << endl;

                    ifstream descFile(filePath, ios::in);
                    string str(std::istreambuf_iterator<char>{descFile}, {});
                    descFile.close();
                    rtrim(str);
                    
                    cout << "| DESCRIPTION : " + str << endl;
                    cout << separator << endl;
                }
                else if (fileName == "run") {
                    ifstream runFile(filePath, ios::in);
                    string str(std::istreambuf_iterator<char>{runFile}, {});
                    runFile.close();
                    rtrim(str);
                    execCmd += "cd ./" + directoryName + " && ./" + str;
                }
                else if (fileName == "std.in") {
                    takeInput = true;
                }
                else if (fileName == "std.out") {
                    compareOutput = true;
                }
                else if (fileName == "stderr.out") {
                    compareError = true;
                }
            }

            execCmd += (takeInput) ? " <std.in" : "";
            execCmd += (compareOutput) ? " >temp.txt" : " >dump.txt";
            execCmd += (compareError) ? " 2>temperr.txt" : " 2>dump.txt";

            system(execCmd.c_str());

            // TODO: Add remaining checking code
            bool passedTests = true;
            for (const auto &filePath : fileList) {
                string fileName = filePath.filename().string();
                if (fileName == "std.out") {
                    if (checkFiles("./" + directoryName + "/std.out", "./" + directoryName + "/temp.txt")) {
                        cout << "                                       Stdout\t: PASSED" << endl;
                    }
                    else {
                        cout << "                                       Stdout\t: FAILED" << endl;
                        passedTests = false;
                    }
                }
                else if (fileName == "stderr.out") {
                    if (checkFiles("./" + directoryName + "/stderr.out", "./" + directoryName + "/temperr.txt")) {
                        cout << "                                       Stderr\t: PASSED" << endl;
                    }
                    else {
                        cout << "                                       Stderr\t: FAILED" << endl;
                        passedTests = false;
                    }
                }
            }

            if (passedTests) {
                cout << "                                       Global\t: PASSED" << endl;
                cptPassed++;
            }
            else {
                cout << "                                       Global\t: FAILED" << endl;
                cptFailed++;
            }

            //remove(("./" + directoryName + "/temperr.txt").c_str());
            //remove(("./" + directoryName + "/temp.txt").c_str());
            //remove(("./" + directoryName + "/dump.txt").c_str());
        }
    }

    cout << "Passed tests     : " << cptPassed << endl;
    cout << "Failed tests     : " << cptFailed << endl;
    cout << "-----------------------" << endl;
    cout << "Total            : " << cptPassed + cptFailed << endl;

    return 0;
}
