#include "fileIOs_wordPairs.h"
#include <iostream>
using namespace NS_WORDPAIRS;

int main(){
    std::string fileName = "inputFile.txt";
    std::string rawText = "";
    std::vector<std::string> sentences;
    int option = 1;

    std::cout << "Would you like to: \n"
        << "Enter a file to be tokenized? (0)\n"
        << "Load a preexisting file for debugging? (1)\n"
        << "Test custom input on ZyBooks? (2)\n";
    std::cin >> option;

    switch (option) {
    case 0:
        std::cout << "Please enter the file (filepath including the extension) you would like to tokenize." << std::endl;
        std::cin >> fileName;
        sentenceSplitter(fileName, sentences);
        break;
    case 1:
        std::cout << "Attempting to load " << fileName << "...\n\n" << std::endl;
        sentenceSplitter(fileName, sentences);
        break;
    case 2:
        std::cout << "Please enter \"2\" in the input box next run, hit enter, then paste your text, and finally press Run program" << std::endl;
        std::cin >> rawText;
        sentenceSplitterZYB(rawText, sentences);
        break;
    default:
        std::cout << "Attempting to load " << fileName << "...\n\n" << std::endl;
        sentenceSplitter(fileName, sentences);
        break;
    }
   
    //call functions from fileIOs_wordpairs.cpp
    //call unit tests

    return -1;
}