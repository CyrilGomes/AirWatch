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

// From StackOverflow: https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
inline void rtrim(std::string &s)
{
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
}

bool checkFiles(const string &filename1, const string &filename2)
{
    ifstream file1(filename1, ios::in);
    string str1(std::istreambuf_iterator<char>{file1}, {});
    file1.close();

    ifstream file2(filename2, ios::in);
    string str2(std::istreambuf_iterator<char>{file2}, {});
    file2.close();

    str1.erase(remove(str1.begin(),str1.end(),'\n'),str1.end());
    str1.erase(remove(str1.begin(),str1.end(),'\r'),str1.end());
    str1.erase(remove(str1.begin(),str1.end(),' '),str1.end());
    str2.erase(remove(str2.begin(),str2.end(),'\n'),str2.end());
    str2.erase(remove(str2.begin(),str2.end(),'\r'),str2.end());
    str2.erase(remove(str2.begin(),str2.end(),' '),str2.end());

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

    // For each Test directory
    for (const auto &file : directory_iterator("./"))
    {
        string directoryName = file.path().filename().string();
        filesystem::path path = file.path();
        if (is_directory(file) && directoryName.find("Test") != string::npos)
        {
            
            // Reset local files
            system("cp ./BaseDataSet/Local/individuals_reference.csv ./BaseDataSet/Local/individuals.csv");
            system("cp ./BaseDataSet/Local/logins_reference.csv ./BaseDataSet/Local/logins.csv");
            
            // Initialize variables
            vector<filesystem::path> fileList = getFilesInDirectory(directoryName);
            string execCmd = "";
            bool takeInput = false;
            bool compareOutput = false;
            bool compareError = false;
            
            // For each file within the directory
            for (const auto &filePath : fileList) {
                string fileName = filePath.filename().string();
                // Print description
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
                // Save the run command
                else if (fileName == "run") {
                    ifstream runFile(filePath, ios::in);
                    string str(std::istreambuf_iterator<char>{runFile}, {});
                    runFile.close();
                    rtrim(str);
                    execCmd += "cd ./" + directoryName + " && ./" + str;
                }
                // Determine intput / output / error output check flags
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

            // Redirect outputs
            execCmd += (takeInput) ? " <std.in" : "";
            execCmd += (compareOutput) ? " >temp.txt" : " >dump.txt";
            execCmd += (compareError) ? " 2>temperr.txt" : " 2>dump.txt";

            // Execute the test
            system(execCmd.c_str());

            // Check outputs, error logs, and csvs (TODO)
            bool passedTests = true;
            if (compareOutput) {
                if (checkFiles("./" + directoryName + "/std.out", "./" + directoryName + "/temp.txt")) {
                    cout << "                                       Stdout\t: PASSED" << endl;
                }
                else {
                    cout << "                                       Stdout\t: FAILED" << endl;
                    passedTests = false;
                }
            }
            if (compareError) {
                if (checkFiles("./" + directoryName + "/stderr.out", "./" + directoryName + "/temperr.txt")) {
                    cout << "                                       Stderr\t: PASSED" << endl;
                }
                else {
                    cout << "                                       Stderr\t: FAILED" << endl;
                    passedTests = false;
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
