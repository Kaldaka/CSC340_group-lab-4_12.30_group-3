#include "fileIOs_wordPairs.h"
#include <iostream>

int main(){
    std::string fileName = "";
    std::vector<std::string> sentences;

    std::cout << "Please enter a filename you wish to analyze\n\n\tNote: please enter the file extension as well\n";
    std::cin >> fileName;
    
    NS_WORDPAIRS::sentenceSplitter(fileName, sentences);

    //call functions from fileIOs_wordpairs.cpp
    //call unit tests

    return -1;
}