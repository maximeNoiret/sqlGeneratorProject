/**
 * @author NOIRET Maxime
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// wtf is this piece of crap?????
void flushCin() {
    // Only ignore if there's pending input
    if (cin.rdbuf()->in_avail() > 0) {
        cin.ignore(numeric_limits<streamsize>::max());
    }
    // Otherwise, do nothing (don't block)
}

string getInput(const string& prompt) {
    cout << prompt << (prompt == "" ? "SqlGenerator" : "\n") << ">> ";
    string input;
    getline(cin, input);
    return input;
}

void printHelp() {
    cout << "Help" << '\n' << '\n'
         << setw(30) << left << "set template"
         << "Sets the template for the SQL generation." << '\n'
         << setw(30) << left << "generate sql"
         << "Generates the SQL data script from template." << '\n'
         << setw(30) << left << "exit"
         << "Exits the program." << '\n';
}

void printVect(const vector<string>& vect) {
    for (const string& elem : vect)
        cout << elem << '\n';
}
