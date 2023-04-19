#ifndef WORDPAIRS_H
#define WORDPAIRS_H

#include <vector>
#include <map>
#include <utility>
#include <string>
#include <list>
#include <iostream>

namespace NS_WORDPAIRS {

    void sentenceSplitter(std::string& fname, std::vector<std::string>& sentences);

    void sentenceSplitterZYB(std::string& text, std::vector<std::string>& sentences);

    void tokenMaker(std::vector<std::string>& tokens, const std::string& sentence);

    void pairMaker(const std::vector<std::string>& tokens, std::list<std::pair<std::string, std::string>>& tokenPairs);

    void wordpairMapping(std::vector<std::string>& sentences, std::map<std::pair<std::string, std::string>, int>& wordpairFreq_map);

    void freqWordpairMmap(std::map<std::pair<std::string, std::string>, int>& wordpairFreq_map, std::multimap<int, std::pair<std::string, std::string> >& freqWordpair_mmap);

    void printWordpairs(std::multimap<int, std::pair<std::string, std::string> >& freqWordpair_multimap, std::string outFname, int topCnt, int botCnt);

    /*** Unit tests ***/

    inline
        bool test1_sentenceSplitter() {
        std::vector<std::string> testMatrix;
        std::string testString = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
        std::vector<std::string> control = { "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua","Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat","Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur","Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum" };
        NS_WORDPAIRS::sentenceSplitterZYB(testString, testMatrix);
        return (testMatrix == control);
    }
}
#endif