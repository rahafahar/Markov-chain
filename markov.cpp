#include "markov.h"
#include <cstdlib>
#include <fstream>


std::string joinWords(const std::string words[], int startIndex, int count) {
    
    std::string result = "";
    
    for(int i = 0; i < count ; ++i) {
       
        result += words[startIndex + i];
        
        if(i < count - 1){
            result += " ";
        }
    }
    

    return result;
}

/*
int readWordsFromFile(std::string filename, std::string words[], int maxWords) {

    std::ifstream inputFile;

    bool isOpen = inputFile.is_open();
    int counter = 0;
    while (counter < maxWords && inputFile >> words[counter]) {
        counter++;
    }

    inputFile.close();

    return counter;
}

int buildMarkovChain(const std::string words[], int numWords, int order, std::string prefixes[], std::string suffixes[], int maxChainSize) {

    int count;

    if(order < 1 || order > 3 || numWords <= order || maxChainSize <= 0) {
        return 0;
    } else {
        count = 0;
    
        int i = 0;
        while(i < numWords - order && count < maxChainSize) {
            std::string prefix = joinWords(words, i , order);
            std::string suffix = words[i + order];
            prefixes[count] = prefix;  
            suffixes[count] = suffix;
            count++;
        }
    }

    return count;
}


std::string getRandomSuffix(const std::string prefixes[], const std::string suffixes[],  int chainSize, std::string currentPrefix) {

    int matchCount = 0;
    for(int i = 0; i <= chainSize - 1; i++){
        if(prefixes[i] == currentPrefix) {
            matchCount++;
        }
         if(matchCount == 0){
        return " ";
        }
    }
   
    int pick = rand() % matchCount;
    int matchCount2 = 0;
    for(int i = 0; i <= chainSize - 1; i++){
        if(prefixes[i] == currentPrefix) {
            matchCount2++;
        }
        if(pick == matchCount2) {
            return suffixes[pick];
        } else {
            return " ";
        }
        
    }
}


std::string getRandomPrefix(const std::string prefixes[], int chainSize) {

    if(chainSize <= 0) {
        return " ";
    } else {
        int index = rand() % chainSize;
        return prefixes[index];
    }
}



std::string generateText(const std::string prefixes[], const std::string suffixes[], int chainSize, int order, int numWords) {
    std::string currentPrefix;
    if(chainSize <= 0 || 1 >= order >= 3 || numWords < order) {
        return "";
    } else {
        currentPrefix = getRandomPrefix(prefixes, chainSize);
    }

    std::string result = currentPrefix;

    std::string currentWords[3];
    int wordIndex = 0;
    std::string temp = "";
    for(int i = 0; i < currentPrefix.length(); i++){
        if(currentPrefix[i] == ' ') {
            currentWords[wordIndex] =  temp;
            wordIndex++;
            temp = "";
        } else {
            temp += currentPrefix[i];
        }
    }

    currentWords[wordIndex] = temp;
}

*/



