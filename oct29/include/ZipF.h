#ifndef ZIPF_H
#define ZIPF_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <map>

namespace zipF {

/**
 * @brief Reads a text file and extracts only alphabetic characters.
 * Non-alphabetic characters are replaced with spaces.
 * @param fileName Name of the text file to read.
 * @return Vector of alphabetic characters from the file with only letters kept.
 */
std::vector<char> readBook(const std::string& fileName);

/**
 * @brief Counts how often each word appears in the text.
 * - It splits the content into words based on spaces.
 * - Then it counts how many times each word appears in the text.
 * @param book Vector of characters representing the book content. (letters only)
 * @return Map with words as keys and their frequencies as values.
 */
std::map<std::string, int> computeWordFrequency(const std::vector<char>& book);

/**
 * @brief Counts the number of unique words in text.
 * @param book Vector of characters representing the book content.
 * @return  The total count of unique words in the book.
 */
int countUniqueWords(const std::vector<char>& book);

/**
 * @brief Sorts words by their frequency, from most to least frequent.
 * 
 *  * This function takes in a map of words (keys) and their frequencies (values).
 * - It creates a new sorted list of words, organized by frequency in descending order.
 * - Words with the same frequency are grouped together.
 * @param frequencies Map of words and their corresponding frequencies.
 * @return Multimap with frequencies as keys and words as values.
 */
std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies);

/**
 * @brief Writes the sorted frequencies to a file in "rank freq word" format.
 * @param sortedFrequencies A sorted multimap with words and their frequencies, from most to least frequent.
 * @param outputFile Name of the output file to save.
 */
void outputFrequencies(const std::multimap<int, std::string, std::greater<>>& sortedFreq, const std::string& outputFileName) ;

/**
 * @brief Prints words that occur only once (hapax legomena) in the sorted frequency list.
 * @param sortedFrequencies A sorted multimap with words and their frequencies.
 */
void plotFrequencies(const std::multimap<int, std::string, std::greater<>>& sortedFreq);

} 

#endif 