#ifndef ZIPF_H
#define ZIPF_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iostream>
#include <matplot/matplot.h>

namespace zipF2 {

// Type alias for word-frequency pairs
using WordFrequency = std::pair<std::string, int>;

/**
 * @brief Reads a book from a file and returns a vector of processed characters.
 *        Only alphabetic characters are retained (converted to lowercase).
 *        Non-alphabetic characters are replaced with spaces.
 *
 * @param fileName Path to the input text file.
 * @return std::vector<char> Processed characters from the book.
 */
std::vector<char> readBook(const std::string& fileName);

/**
 * @brief Computes word frequencies from the processed book content.
 *
 * @param book Vector of processed characters.
 * @return std::vector<WordFrequency> Vector of word-frequency pairs.
 */
std::vector<WordFrequency> computeWordFrequency(const std::vector<char>& book);

/**
 * @brief Counts the number of unique words in the book.
 *
 * @param book Vector of processed characters.
 * @return int Number of unique words.
 */
int countUniqueWords(const std::vector<char>& book);

/**
 * @brief Sorts word frequencies in decreasing order.
 *
 * @param frequencies Vector of word-frequency pairs.
 * @return std::vector<WordFrequency> Sorted vector of word-frequency pairs.
 */
std::vector<WordFrequency> sortFrequencies(std::vector<WordFrequency>& frequencies);

/**
 * @brief Outputs the sorted word frequencies to a file.
 *
 * @param sortedFreq Sorted vector of word-frequency pairs.
 * @param outputFileName Path to the output file.
 */
void outputFrequencies(const std::vector<WordFrequency>& sortedFreq, const std::string& outputFileName);

/**
 * @brief Plots the word frequency distribution on a log-log scale.
 *
 * @param sortedFreq Sorted vector of word-frequency pairs.
 */
void plotFrequencies(const std::vector<WordFrequency>& sortedFreq);

/**
 * @brief Prints the hapax legomena (words that appear only once).
 *
 * @param sortedFreq Sorted vector of word-frequency pairs.
 */
void printHapaxLegomena(const std::vector<WordFrequency>& sortedFreq);

} // namespace zipF

#endif // ZIPF_H
