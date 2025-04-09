/**
 * @author NOIRET Maxime
 */

#include <string>
#include <vector>

#ifndef TERMINALMANAGEMENT_H
#define TERMINALMANAGEMENT_H

/**
 * @brief Flushes the content of cin using cin.ignore().
 */
void flushCin();

/**
 * @brief Function to obtain an input from the user.
 * @param [in] prompt : Prompt to show the user.
 * @return The input from the user.
 */
std::string getInput(const std::string& prompt);

/**
 * @brief Prints the help menu that shows all possible commands.
 */
void printHelp();

/**
 * @brief Prints the content of a vector, each elements printed on a new line.
 * @param [in] vect : Vector to print.
 */
void printVect(const std::vector<std::string>& vect);

#endif // TERMINALMANAGEMENT_H
