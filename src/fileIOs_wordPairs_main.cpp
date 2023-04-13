#include "fileIOs_wordPairs.h"
#include <iostream>

int main(){
    std::string fileName = "inputFile.txt";
    std::string rawText = "";
    std::vector<std::string> sentences;
    int option = 1;

    std::cout << "Would you like to: \n"
        << "Enter a file to be tokenized? (0)\n"
        << "Load a preexisting file for debugging? (1)\n";
    std::cin >> option;

    switch (option) {
    case 0:
        std::cout << "Please enter the file (filepath including the extension) you would like to tokenize." << std::endl;
        std::cin >> fileName;
        NS_WORDPAIRS::sentenceSplitter(fileName, sentences);
        break;
    case 1:
        std::cout << "Attempting to load " << fileName << "...\n\n" << std::endl;
        NS_WORDPAIRS::sentenceSplitter(fileName, sentences);
        break;
    default:
        std::cout << "Attempting to load " << fileName << "...\n\n" << std::endl;
        NS_WORDPAIRS::sentenceSplitter(fileName, sentences);
        break;
    }
   
    //call functions from fileIOs_wordpairs.cpp
    //call unit tests

    return -1;
}