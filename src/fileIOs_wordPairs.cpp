#include "fileIOs_wordPairs.h"
#include <iostream>
#include <fstream>
#include <regex>

namespace NS_WORDPAIRS{

    void sentenceSplitter(std::string& fname, std::vector<std::string>& sentences){
        //TODO: split sentences based on ". or ? or ." or ?" or \n"
        std::map<std::pair<std::string, std::string>, int> wordPairFreq_map;
        std::string fileName = fname;
        std::string line = "";
        std::ifstream inFS;
        std::cout << "opening " << fileName << "..." << std::endl;

        inFS.open(fileName);
        if (!inFS.is_open()) {
            std::cout << "Could not open " << fileName << ", please try again." << std::endl;
            std::cin >> fileName;
            sentenceSplitter(fileName, sentences);
        }

        while (!inFS.fail()) {
            std::getline(inFS, line);
            sentences.push_back(splitter(line));
        }
        wordpairMapping(sentences, wordPairFreq_map);
    }

    std::string splitter(std::string& line) {
        std::regex delim("[.?]\\n?|\"[.?]\"");
        std::string loneSentence = "";
        return loneSentence;
    }

    void wordpairMapping(std::vector<std::string>& sentences, std::map<std::pair<std::string,std::string>, int> &wordpairFreq_map){

    }

    void freqWordpairMmap(std::map<std::pair<std::string,std::string>, int> &wordpairFreq_map, std::multimap<int, std::pair<std::string, std::string> > &freqWordpair_mmap ){

    }

    void printWordpairs(std::multimap<int, std::pair<std::string, std::string> > &freqWordpair_multimap, std::string outFname, int topCnt, int botCnt){

    }

}