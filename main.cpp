#include <cstdlib>
#include <ctime>
#include <iostream>
#include "markov.h"
using namespace std;

int main() {

    srand(time(0));

    string testArray[] = {"the", "cat", "sat", "down"};

    // f 1 test
    cout << joinWords(testArray, 0, 2) << endl;
    cout << joinWords(testArray, 1, 3) << endl;

    // f 2 test
    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    cout << "Read " << count << " words" << endl;
    for(int i = 0; i < 10 && i < count; i++){
        cout << words[i] << endl;
    } 
    // f 3 test
    string prefixes[1000], suffixes[1000];
    int chainSize = buildMarkovChain(testArray, count, 3, prefixes, suffixes, 1000);
    for(int i = 0; i < 20 && i < chainSize; i++) {
        cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << endl;
    }

    //f 4 test
    for(int i = 0; i < 10; i++) {
        cout << getRandomSuffix(prefixes, suffixes, chainSize, "the") << endl;
    }

    //f 5 test
    for(int i = 0; i < 5; i++) {
        cout << getRandomPrefix(prefixes, chainSize) << endl;
    }

    // f 6 test
    cout << " GENERATE TEXT FUNC TEST\n\n" << endl;
    string output = generateText(prefixes, suffixes, chainSize, 1, 20);
    cout << output << endl;

    return 0;
}
