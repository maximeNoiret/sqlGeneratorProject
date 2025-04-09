#include <string>
#include <vector>

#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

/**
 * @brief Opens a file.
 * @param [in] filePath : String containing the path to the file to open.
 * @return A vector of strings, with one element being one line from the file.
 */
std::vector<std::string> openFile(const std::string &filePath);

#endif // FILEMANAGEMENT_H
