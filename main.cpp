#include <cstdlib>
#include <ctime>
#include <iostream>
#include "markov.h"
using namespace std;

int main() {

    srand(time(0));

    string testArray[] = {"the", "cat", "sat", "down"};

    cout << joinWords(testArray, 0, 2) << endl;
    cout << joinWords(testArray, 1, 3) << endl;

    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    cout << "Read " << count << " words" << endl;
    for(int i = 0; i < 10 && i < count; i++){
        cout << words[i] << endl;
    } 

    string prefixes[1000], suffixes[1000];
    int chainSize = buildMarkovChain(testArray, count, 3, prefixes, suffixes, 1000);
    for(int i = 0; i < 20 && i < chainSize; i++) {
        cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << endl;
    }

    return 0;
}
