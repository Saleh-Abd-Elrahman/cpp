#include <matplot/matplot.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include "../include/ZipF.h"

namespace zipF {

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


std::map<std::string, int> computeWordFrequency(const std::vector<char>& book){
    std::map<std::string, int> wordFrequency;
    std::stringstream ss;
    std::string word;
    for (char c : book){
        if (c == ' '){
            ss >> word;
            if (wordFrequency.find(word) == wordFrequency.end()){
                wordFrequency[word] = 1;
            } else {
                wordFrequency[word]++;
            }
            ss.clear();
            ss.str("");
        } else {
            ss << c;
        }
    }
    return wordFrequency;
}

int countUniqueWords(const std::vector<char>& book){
    std::set<std::string> uniqueWords;
    std::stringstream ss;
    std::string word;
    for (char c : book){
        if (c == ' '){
            ss >> word;
            uniqueWords.insert(word);
            ss.clear();
            ss.str("");
        } else {
            ss << c;
        }
    }
    return uniqueWords.size();

}

std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies){
    std::multimap<int, std::string, std::greater<>> sortedFrequencies;
    for (const auto& pair : frequencies){
        sortedFrequencies.insert(std::make_pair(pair.second, pair.first));;
    }
    return sortedFrequencies;
}

void outputFrequencies(const std::multimap<int, std::string, std::greater<>>& sortedFreq, const std::string& outputFileName) {
    std::ofstream outFile(outputFileName);

    if (!outFile) {
        std::cerr << "Error opening file: " << outputFileName << std::endl;
        return;
    }

    int rank = 1;
    for (const auto& [frequency, word] : sortedFreq) {  // Structured Binding
        outFile << rank << " " << frequency << " " << word << std::endl;
        rank++;
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

// for printing the hapax legomena
void printHapaxLegomena(const std::multimap<int, std::string, std::greater<>>& sortedFreq) {
    int count = 0;

    for (const auto& [frequency, word] : sortedFreq) {
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

int main() {
    std::string inputFileName = "../../books/pg2701.txt";    // Replace with your input file name
    std::string outputFileName = "output.txt";  // Replace with your desired output file name

    // Milestone 1: Read the book
    std::vector<char> bookContent = zipF::readBook(inputFileName);

    // Milestone 2: Compute word frequencies
    std::map<std::string, int> wordFreq = zipF::computeWordFrequency(bookContent);

    // Milestone 3: Count unique words
    int uniqueWordCount = zipF::countUniqueWords(bookContent);
    std::cout << "Number of unique words: " << uniqueWordCount << std::endl;

    // Milestone 4: Sort the frequencies
    auto sortedFreq = zipF::sortFrequencies(wordFreq);

    // Milestone 5: Output frequencies to file
    zipF::outputFrequencies(sortedFreq, outputFileName);
    std::cout << "Word frequencies have been written to " << outputFileName << std::endl;

    zipF::printHapaxLegomena(sortedFreq);

    // Advanced Milestone: Plot frequencies
    zipF::plotFrequencies(sortedFreq);

    return 0;
}
