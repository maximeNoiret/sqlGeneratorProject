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

/**
 * @brief Write data into a file.
 * @param [in] filePath : The path to the file into which to write.
 * @param [in] data : The data to write, one element per line.
 */
void writeFile(const std::string& filePath, const std::vector<std::string>& data);

#endif // FILEMANAGEMENT_H
