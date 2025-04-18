/**
 * @author NOIRET Maxime
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../headers/terminalManagement.h"

using namespace std;

// Genuinely horrifying.
vector<string> getAttributes() {
    vector<string> attributes;
    cout << "Enter attributes:" << endl;
    string attrs;
    getline(cin, attrs);
    string attr;

    for (stringstream attrStream(attrs);attrStream.good();) {
        attrStream >> attr;
        if (attr == ":q") break;
        attributes.push_back(attr);
    }
    return attributes;
}

vector<char> getTypes(const vector<string>& attributes) {
    vector<char> types;
    string bruh;
    char type;
    for (const string& attribute : attributes) {
        for (;;) {
            cout << "Enter domain for "
                 << (attribute == *attributes.begin()
                         ? "PRIMARY KEY "
                         : "")
                 << "\"" << attribute
                 << "\" (c=string, n=number, h=hierarchy): ";

            getline(cin, bruh);
            type = bruh[0];
            if (type == 'c' || type == 'n' || type == 'h')
                break;  // FIXME: find a way to NOT use break :3
            else
                cout << "Incorrect! Only use:\n"
                     << "\t'c' for CHAR/VARCHAR/VARCHAR2,\n"
                     << "\t'n' for NUMBER and\n"
                     << "\t'h' for a hierarchy parent attribute!\n";
        }
        types.push_back(type);
    }
    return types;
}

string setTemplate(const vector<string>& attributes) {
    string relationName;
    cout << "Enter the name of the relation: ";
    getline(cin, relationName);
    string tmplate = "INSERT INTO " + relationName + "(";
    string valPlate;
    vector<char> types = getTypes(attributes);
    for (size_t i = 0; i < attributes.size(); ++i) {
        string dataStr = "data_";
        string hierarchyparentstring = "data_HIERARCHY_PARENT";
        tmplate += attributes[i] + (i + 1 == attributes.size() ? "" : ", ");
        valPlate += (types[i] == 'h' ? (types[0] == 'c' ? "'" : "") +
                                           hierarchyparentstring +
                                           (types[0] == 'c' ? "'" : "")
                                     : (types[i] == 'c' ? "'" : "") +
                                           dataStr + attributes[i] +
                                           (types[i] == 'c' ? "'" : "")) +
                    (i + 1 == types.size() ? "" : ", ");
    }
    tmplate += ") VALUES (" + valPlate + ");";
    cout << tmplate << '\n';
    return tmplate;
}

bool replaceStr(string& str, const string& target, const string& data) {
    size_t pos = str.find(target);
    if (pos == str.npos) return false;
    str.replace(str.find(target), target.size(), "");
    str.insert(pos, data);
    return true;
}

// Comes from S2.04
vector<string> splitData(const string& data) {
    vector<string> formattedData;
    string tmp = data.substr(data.find(':')+1, data.size());  // remove LEVEL
    for (;tmp.find('|') != tmp.npos;) {
        formattedData.push_back(tmp.substr(0,tmp.find('|')));
        tmp.erase(0, tmp.find('|')+1);
    }
    formattedData.push_back(tmp.substr(0,tmp.find('\n')));
    return formattedData;
}

// Comes from S2.04
size_t getLevel(const string &data) {
    return data.substr(0, data.find(':')).size();
}

// Comes from S2.04
size_t getParent(const vector<string>& fileData,
                 const size_t& currentPosition) {
    size_t currentLevel = getLevel(fileData[currentPosition]);
    if (currentLevel == 0) return 0;  // if root, return null value
    size_t parentPosition = currentPosition-1;
    for (;parentPosition > 0 &&
           getLevel(fileData[parentPosition]) != currentLevel-1;
         --parentPosition);
    return parentPosition;
}

/* PS: tupleData should be formatted as such:
 * (-*LEVEL):ATTR|ATTR|ATTR
 */
string generateTuple(const vector<string>& attributes,
                     const string& tmplate,
                     const vector<string>& tupleData,
                     const string& parent) {
    string tuple = tmplate;
    replaceStr(tuple, "data_HIERARCHY_PARENT", parent);
    for (size_t i = 0; i < attributes.size(); ++i) {
        replaceStr(tuple, "data_" + attributes[i], tupleData[i]);
    }
    return tuple;
}

/* PLAN
 * For each line in data, generate a tuple from it.
 */
vector<string> generateSQL(const vector<string>& attributes,
                           const string& tmplate,
                           const vector<string>& data) {
    vector<string> sql;
    for (size_t i = 1; i < data.size(); ++i) {
        string tuple = generateTuple(attributes,
                                     tmplate,
                                     splitData(data[i]),
                                     (splitData(data[getParent(data, i)])[0]));  // PK of parent
        sql.push_back(tuple);
        cout << tuple << '\n';
    }
    return sql;
}
