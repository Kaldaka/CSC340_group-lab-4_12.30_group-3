#include "fileIOs_wordPairs.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <iterator>

namespace NS_WORDPAIRS{

    void sentenceSplitter(std::string& fname, std::vector<std::string>& sentences){
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
            if (line != "") {
                while (it != line.end()) {
                    if (*it == '.' || *it == '?') {
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

        wordpairMapping(sentences, wordPairFreq_map);
        inFS.close();
    }

    void wordpairMapping(std::vector<std::string>& sentences, std::map<std::pair<std::string,std::string>, int> &wordpairFreq_map){

    }

    void freqWordpairMmap(std::map<std::pair<std::string,std::string>, int> &wordpairFreq_map, std::multimap<int, std::pair<std::string, std::string> > &freqWordpair_mmap ){

    }

    void printWordpairs(std::multimap<int, std::pair<std::string, std::string> > &freqWordpair_multimap, std::string outFname, int topCnt, int botCnt){

    }

}