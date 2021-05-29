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
inline vector<string> split(const string &text, const char &sep)
{
    string tmp;
    vector<string> stk;
    stringstream ss(text);
    while (getline(ss, tmp, sep))
    {
        stk.push_back(tmp);
    }
    return stk;
}

// https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
inline void rtrim(std::string &s)
{
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
}

bool checkFiles(const string &filename1, const string &filename2)
{
    // Get strings contained in each file
    ifstream file1(filename1, ios::in);
    string str1(std::istreambuf_iterator<char>{file1}, {});
    file1.close();
    ifstream file2(filename2, ios::in);
    string str2(std::istreambuf_iterator<char>{file2}, {});
    file2.close();
    
    // Remove whitespace characters and spaces (facilitates tests)
    str1.erase(remove(str1.begin(),str1.end(),'\n'),str1.end());
    str1.erase(remove(str1.begin(),str1.end(),'\r'),str1.end());
    str1.erase(remove(str1.begin(),str1.end(),' '),str1.end());
    str2.erase(remove(str2.begin(),str2.end(),'\n'),str2.end());
    str2.erase(remove(str2.begin(),str2.end(),'\r'),str2.end());
    str2.erase(remove(str2.begin(),str2.end(),' '),str2.end());

    // Check equality
    return str1 == str2;
}

bool checkCSVs(const string &filename1, const string &filename2)
{
    // Get strings contained in each file
    ifstream file1(filename1, ios::in);
    string str1(std::istreambuf_iterator<char>{file1}, {});
    file1.close();
    ifstream file2(filename2, ios::in);
    string str2(std::istreambuf_iterator<char>{file2}, {});
    file2.close();
    
    // Split files in lines 
    vector<string> file1Lines = split(str1, '\n');
    vector<string> file2Lines = split(str2, '\n');
    
    // Check if number of lines from file 2 = the number specified in line 1 of file 1
    bool lineNumberCheck = file2Lines.size() == atoi(file1Lines[0].c_str());
    if (!lineNumberCheck) return false;
    
    // For each line > 1 in file 1
    bool linesContained = true;
    int len = file1Lines.size();
    for (int i = 1; i < len; i++) {
        // Check that it is contained in file 2 (if not, end test)
        if (str2.find(file1Lines[i]) == string::npos) {
            linesContained = false;
            break;
        }
    }
    return linesContained;
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
            system(("mkdir -p ./" + directoryName + "/Dataset").c_str());
            system(("cp -r ./BaseDataset/Central ./" + directoryName + "/Dataset/").c_str());
            system(("cp -r ./BaseDataset/Local ./" + directoryName + "/Dataset/").c_str());
            
            // Initialize variables
            vector<filesystem::path> fileList = getFilesInDirectory(directoryName);
            string execCmd = "";
            bool takeInput = false;
            bool compareOutput = false;
            bool compareError = false;
            bool compareLoginsCSV = false;
            bool compareIndividualsCSV = false;
            
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
                else if (fileName == "logins.csv.outfile") {
                    compareLoginsCSV = true;
                }
                else if (fileName == "individuals.csv.outfile") {
                    compareIndividualsCSV = true;
                }
            }

            // Redirect outputs
            execCmd += (takeInput) ? " <std.in" : "";
            execCmd += (compareOutput) ? " >temp.txt" : " >dump.txt";
            execCmd += (compareError) ? " 2>temperr.txt" : " 2>dump.txt";

            // Execute the test
            system(execCmd.c_str());

            // Determine whether the test passed or not
            bool passedTests = true;
            // Check outputs (if applicable)
            if (compareOutput) {
                if (checkFiles("./" + directoryName + "/std.out", "./" + directoryName + "/temp.txt")) {
                    cout << "                                       Stdout\t: PASSED" << endl;
                }
                else {
                    cout << "                                       Stdout\t: FAILED" << endl;
                    passedTests = false;
                }
            }
            // Check errors (if applicable)
            if (compareError) {
                if (checkFiles("./" + directoryName + "/stderr.out", "./" + directoryName + "/temperr.txt")) {
                    cout << "                                       Stderr\t: PASSED" << endl;
                }
                else {
                    cout << "                                       Stderr\t: FAILED" << endl;
                    passedTests = false;
                }
            }
            // Check csvs (if applicable)
            if (compareLoginsCSV) {
                if (checkCSVs("./" + directoryName + "/logins.csv.outfile", "./" + directoryName + "/Dataset/Local/logins.csv")) {
                    cout << "                                       CSV 1\t: PASSED" << endl;
                }
                else {
                    cout << "                                       CSV 1\t: FAILED" << endl;
                    passedTests = false;
                }
            }
            if (compareIndividualsCSV) {
                if (checkCSVs("./" + directoryName + "/individuals.csv.outfile", "./" + directoryName + "/Dataset/Local/individuals.csv")) {
                    cout << "                                       CSV 2\t: PASSED" << endl;
                }
                else {
                    cout << "                                       CSV 2\t: FAILED" << endl;
                    passedTests = false;
                }
            }
            
            // Show global results
            if (passedTests) {
                cout << "                                       Global\t: PASSED" << endl;
                cptPassed++;
            }
            else {
                cout << "                                       Global\t: FAILED" << endl;
                cptFailed++;
            }

            // Cleanup output redirection files
            remove(("./" + directoryName + "/temperr.txt").c_str());
            remove(("./" + directoryName + "/temp.txt").c_str());
            remove(("./" + directoryName + "/dump.txt").c_str());
        }
    }

    /* ALL TESTS */
    cout << "Passed tests     : " << cptPassed << endl;
    cout << "Failed tests     : " << cptFailed << endl;
    cout << "-----------------------" << endl;
    cout << "Total            : " << cptPassed + cptFailed << endl;

    return 0;
}
