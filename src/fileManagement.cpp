#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

// Comes from S2.04
vector<string> openFile(const string &filePath) {
    vector<string> fileData;
    fileData.push_back("null");  // for getParent (null value)

    ifstream file(filePath);
    if (!file) {
        cerr << "Incorrect file." << '\n'
             << "Make sure the file exists and the path is correct.";
        exit(1);
    }
    for (string line;getline(file, line);) {
        if (line.substr(0, 2) == "//" || line.empty()) continue;
        fileData.push_back(line);
    }
    return fileData;
}

void writeFile(const string& filePath, const vector<string>& data) {
    ofstream file(filePath);
    if (!file) {
        cerr << "Incorrect file." << '\n'
             << "Make sure the file exists and the path is correct.";
    }
    for (const string& line : data) {
        file << line << '\n';
    }
}
