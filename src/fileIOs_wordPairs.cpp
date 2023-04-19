#include "fileIOs_wordPairs.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <iterator>
#include <sstream>

namespace NS_WORDPAIRS {

    void sentenceSplitter(std::string& fname, std::vector<std::string>& sentences) {
        std::map<std::pair<std::string, std::string>, int> wordPairFreq_map;
        std::string fileName = fname;
        std::string line = "";
        std::ifstream inFS;

        inFS.open(fileName);
        if (!inFS.is_open()) {
            std::cout << "Could not open " << fileName << ", please try again." << std::endl;
            std::cin >> fileName;
            sentenceSplitter(fileName, sentences);
        }

        while (std::getline(inFS, line)) {
            std::string::iterator it = line.begin();
            int fromIndex = 0;
            int toIndex = it - line.begin();
            if (line != "") {//covers paragraph spacers that are empty strings
                while (it != line.end()) {//iterates over each continuous block of text between newlines
                    if (*it == '.' || *it == '?' || (*it == ':' && it+1 == line.end())) {
                        toIndex = (it - line.begin()) - fromIndex;
                        sentences.push_back(line.substr(fromIndex, toIndex));
                        if (it + 1 != line.end() && *(it + 1) == '"') {
                            fromIndex = it - line.begin() + 3;
                        }
                        else {
                            fromIndex = it - line.begin() + 2;
                        }
                    }
                    it++;
                }
            }
        }

        int count = 0;
        for (std::string sentence : sentences) {
            count++;
            std::cout << "sentence " << count << ": " << sentence << std::endl;
        }

        wordpairMapping(sentences, wordPairFreq_map);
        inFS.close();
    }

    void sentenceSplitterZYB(std::string& text, std::vector<std::string>& sentences) {
        std::ofstream outFS;
        std::string fName = "test_text_to_parse.txt";

        outFS.open(fName);

        if (!outFS.is_open()) {
            std::cout << "could not open or create file." << std::endl;
            return;
        }

        outFS << text;
        outFS.close();

        sentenceSplitter(fName, sentences);
    }

    // utilizing a vector to get the tokens from the sentences
    void tokenMaker(std::vector<std::string>& tokens, const std::string& sentence) {
        std::istringstream iss(sentence);
        std::string word;
        while (iss >> word) {
            // convert to lowercase
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            tokens.push_back(word);
        }
    }

    // taking a list of tokens and converting them in to pairs one by one through comparison
    void pairMaker(const std::vector<std::string>& tokens, std::list<std::pair<std::string, std::string>>& tokenPairs) {
        for (size_t i = 0; i < tokens.size() - 1; i++) {
            for (size_t j = i + 1; j < tokens.size(); j++) {
                //checking to see if the words are same
                if (tokens[i] != tokens[j]) {
                    std::string first = tokens[i];
                    std::string second = tokens[j];
                    // arranging the pair in lexicographical order
                    if (first > second) {
                        std::swap(first, second);
                    }
                    tokenPairs.push_back(std::make_pair(first, second));
                }
            }
        }
    }

    void wordpairMapping(std::vector<std::string>& sentences, std::map<std::pair<std::string, std::string>, int>& wordpairFreq_map) {
        for (const std::string& sentence : sentences) {
            std::vector<std::string> tokens;
            tokenMaker(tokens, sentence);
            std::list<std::pair<std::string, std::string>> tokenPairs;
            pairMaker(tokens, tokenPairs);
            std::map<std::pair<std::string, std::string>, bool> pairAlreadyCounted;
            for (const auto& pair : tokenPairs) {
                // check if the pair has already been counted in the current sentence
                if (wordpairFreq_map[pair] == 0 || !pairAlreadyCounted[pair])
                {
                    // update the frequency in the map
                    wordpairFreq_map[pair]++;
                    pairAlreadyCounted[pair] = true;
                }
            }
        }
    }

    void freqWordpairMmap(std::map<std::pair<std::string, std::string>, int>& wordpairFreq_map, std::multimap<int, std::pair<std::string, std::string> >& freqWordpair_mmap) {
        for (const auto& pair : wordpairFreq_map) {
            freqWordpair_mmap.insert(std::make_pair(pair.second, pair.first));
        }
    }

    void printWordpairs(std::multimap<int, std::pair<std::string, std::string> >& freqWordpair_multimap, std::string outFname, int topCnt, int botCnt) {
        std::ofstream outFile(outFname);

        if (!outFile.is_open()) {
            std::cout << "Error opening output file." << std::endl;
            return;
        }

        outFile << "Top " << topCnt << " most frequent word-pairs:" << std::endl;
        auto rit = freqWordpair_multimap.rbegin();
        for (int i = 0; i < topCnt && rit != freqWordpair_multimap.rend(); ++i, ++rit) {
            outFile << "<" << rit->second.first << ", " << rit->second.second << ">: " << rit->first << std::endl;
        }

        outFile << std::endl;

        outFile << "Top " << botCnt << " least frequent word-pairs:" << std::endl;
        auto it = freqWordpair_multimap.begin();
        for (int i = 0; i < botCnt && it != freqWordpair_multimap.end(); ++i, ++it) {
            outFile << "<" << it->second.first << ", " << it->second.second << ">: " << it->first << std::endl;
        }

        outFile.close();
    }
}
