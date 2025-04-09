/**
 * @author NOIRET Maxime
 */

#include <iostream>
#include <fstream>
#include <string>
#include "../headers/terminalManagement.h"
#include "../headers/sqlManagement.h"
#include "../headers/fileManagement.h"

using namespace std;

int main(const int argc, const char** argv) {
    string tmplate;
    vector<string> attributes;
    vector<string> sqlData;
    for (string input;input != "quit" && input != "exit" && input != ":q";) {
        flushCin();
        input = getInput("");
		if (input == "help" || input == "h")
			printHelp();
        else if (input == "set template") {
            attributes = getAttributes();
            tmplate = setTemplate(attributes);
        } else if (input == "generate sql") {
            sqlData = generateSQL(attributes,
                                  tmplate,
                                  openFile(getInput("Enter file path:")));
            printVect(sqlData);
            cout << "Enter output file name (:q to not write to file): ";
            getline(cin, input);
            if (input != ":q")
                writeFile(input, sqlData);
            input = "";
        }
	}
	return 0;
}
