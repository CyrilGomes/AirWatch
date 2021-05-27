#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <unistd.h>

using namespace std;
using std::filesystem::directory_iterator;

vector<string> split(const string& text) {
    string tmp;
    vector<string> stk;
    stringstream ss(text);
    while(getline(ss,tmp,' ')) {
        stk.push_back(tmp);
    }
    return stk;
}

int main()
{
    for (const auto &file : directory_iterator("./"))
    {
        string directoryName = file.path().filename().string();
        filesystem::path path = file.path();
        if (is_directory(file) && directoryName.find("Test") != string::npos)
        {
            filesystem::path runPath = path;
            runPath += "/run";
            ifstream runFile(runPath, ios::in);
            string str(std::istreambuf_iterator<char>{runFile}, {});

            string execCmd = "cd ./" + directoryName + " && ./" + str;
            
            for (const auto &file : directory_iterator("./" + directoryName)){
                if(!is_directory(file)){
                    string fileName = file.path().filename().string();
                    if(fileName == "description"){

                    }
                    else if(fileName == "std.in"){
                        execCmd += " <std.in";
                    }
                    else if(fileName == "std.out"){
                        execCmd += " >temp.txt";
                    }
                    else if (fileName == "stderr.out"){
                        execCmd += " 2>temperr.txt";
                    }
                }
            }

            cout << execCmd << endl;
            system(execCmd.c_str());
            
            // TODO: Add checking code

            remove(("./" + directoryName + "/temperr.txt").c_str());
            remove(("./" + directoryName + "/temp.txt").c_str());
        }
    }
    return 0;
}