#include "../include/ZipF_2.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

namespace zipF2 {

// for reading the book
std::vector<char> readBook(const std::string& fileName) {
    std::ifstream file(fileName);
    std::vector<char> result;

    if (file.is_open()) {
        char c;
        while (file.get(c)) {
            if (std::isalpha(c)) {
                result.push_back(std::tolower(c));  // lowercase
            } else {
                result.push_back(' ');
            }
        }
    }
    return result;
}

// for counting the frequency of each word
std::vector<std::pair<std::string, int>> computeWordFrequency(const std::vector<char>& book) {
    std::stringstream ss(std::string(book.begin(), book.end()));
    std::vector<std::string> words;
    std::string word;

    while (ss >> word) {
        words.push_back(word);
    }

    std::sort(words.begin(), words.end()); 

    // Vector to store pairs
    std::vector<std::pair<std::string, int>> wordFrequency;

    // counting the frequency of each word by iterating through the sorted vector
    auto it = words.begin();
    while (it != words.end()) {
        auto endIt = std::find_if(it, words.end(), [it](const std::string& w) { return w != *it; });
        int count = std::distance(it, endIt);
        wordFrequency.emplace_back(*it, count);
        it = endIt;
    }

    // Sort wordFrequency vector by frequency in descending order
    std::sort(wordFrequency.begin(), wordFrequency.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    return wordFrequency;
}

// for counting the number of unique words
int countUniqueWords(const std::vector<std::pair<std::string, int>>& wordFrequency) {
    return wordFrequency.size(); 
}

// for writing the sorted frequencies to a file
void writeFrequenciesToFile(const std::vector<std::pair<std::string, int>>& sortedFrequencies, const std::string& outputFile) {
    std::ofstream file(outputFile);
    int rank = 1;

    for (const auto& [word, frequency] : sortedFrequencies) {
        file << rank << " " << frequency << " " << word << "\n";
        rank++;
    }
}

// for printing the hapax legomena by iterating through the sorted vector
void printHapaxLegomena(const std::vector<std::pair<std::string, int>>& sortedFrequencies) {
    int count = 0;

    for (const auto& [word, frequency] : sortedFrequencies) {
        if (frequency == 1) {
            count++;
            if (count <= 10) {  
                std::cout << word << "\n";
            }
        }
    }

    std::cout << "Total hapax legomena: " << count << std::endl;
}

} 

void plotFrequencies(const std::multimap<int, std::string, std::greater<>>& sortedFreq) {
    std::vector<double> ranks;
    std::vector<double> frequencies;

    int rank = 1;
    for (const auto& pair : sortedFreq) {
        ranks.push_back(static_cast<double>(rank));
        frequencies.push_back(static_cast<double>(pair.first));
        rank++;
    }

    // Create a new figure
    matplot::figure();
    
    // Plot on a log-log scale
    matplot::loglog(ranks, frequencies, "r*-");
    matplot::xlabel("Rank");
    matplot::ylabel("Frequency");
    matplot::title("Word Frequency Distribution (Log-Log Scale)");
    
    // Optionally, add grid for better readability
    matplot::grid(matplot::on);
    
    // Display the plot
    matplot::show();
}

int main() {
    // Specify the input and output file paths
    std::string inputFileName = "../../books/pg2701.txt";       // Replace with your input file path
    std::string outputFileName = "results.txt"; // Replace with your desired output file path

    // Step 1: Read the book
    std::cout << "Reading the book from " << inputFileName << "..." << std::endl;
    std::vector<char> bookContent = zipF2::readBook(inputFileName);
    std::cout << "Book content read successfully. Total characters: " << bookContent.size() << std::endl;

    // Step 2: Compute word frequencies
    std::cout << "Computing word frequencies..." << std::endl;
    std::vector<std::pair<std::string, int>> wordFreq = zipF2::computeWordFrequency(bookContent);
    std::cout << "Word frequencies computed successfully. Total unique words: " << wordFreq.size() << std::endl;

    // Step 3: Count unique words
    int uniqueWordCount = zipF2::countUniqueWords(wordFreq);
    std::cout << "Number of unique words: " << uniqueWordCount << std::endl;

    // Step 4: Write frequencies to output file
    std::cout << "Writing word frequencies to " << outputFileName << "..." << std::endl;
    zipF2::writeFrequenciesToFile(wordFreq, outputFileName);
    std::cout << "Word frequencies written to " << outputFileName << " successfully." << std::endl;

    // Step 5: Print hapax legomena
    std::cout << "\nHapax Legomena (words that appear only once):" << std::endl;
    zipF2::printHapaxLegomena(wordFreq);

    // Step 6: Convert word frequency vector to multimap for plotting
    std::multimap<int, std::string, std::greater<>> sortedFreq;
    for (const auto& pair : wordFreq) {
        sortedFreq.emplace(pair.second, pair.first);
    }

    // Step 7: Plot frequencies
    std::cout << "\nPlotting word frequency distribution..." << std::endl;
    plotFrequencies(sortedFreq);
    std::cout << "Plot displayed successfully." << std::endl;

    return 0;
}