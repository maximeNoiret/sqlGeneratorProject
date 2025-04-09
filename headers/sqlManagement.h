/**
 * @author NOIRET Maxime
 */

#include <string>
#include <vector>

#ifndef SQLMANAGEMENT_H
#define SQLMANAGEMENT_H

/**
 * @brief Function to obtain the attributes of a relation through user input.
 * @return A vector containing the attributes of the relation.
 */
std::vector<std::string> getAttributes();

/**
 * @brief Uses user input and/or files to generate a template string which will be used to generate the SQL insertions.
 * @param [in] attributes : The attributes of the relation.
 * @returns The template.
 */
std::string setTemplate(const std::vector<std::string>& attributes);

/**
 * @brief Generates an SQL INSERT command from a template and formatted data.
 * @param [in] attributes : The attributes of the relation.
 * @param [in] tmplate : The template created using 'set template'.
 * @param [in] tupleData : Data extracted from a formatted line of a file.
 * @param [in] parent : Parent element, determined using getParent().
 * @return A string containing the SQL INSERT command.
 */
std::string generateTuple(const std::vector<std::string>& attributes,
                          const std::string& tmplate,
                          const std::vector<std::string>& tupleData,
                          const std::string& parent);

/**
 * @brief Generate a chain of SQL INSERT commands to create a Data Script.
 * @param [in] attributes : The attributes of the relation.
 * @param [in] tmplate : The template created using 'set template'.
 * @param [in] data : Data from a file, each element being a line.
 * @return A vector of strings, with each element being an SQL INSERT command.
 */
std::vector<std::string> generateSQL(const std::vector<std::string>& attributes,
                                     const std::string& tmplate,
                                     const std::vector<std::string>& data);

#endif // SQLMANAGEMENT_H
