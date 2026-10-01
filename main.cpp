#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "markov.h"
using namespace std;

int main() {

    srand(time(0));
    const int MAX_WORDS = 5000;
    string words[MAX_WORDS];
    string prefixes[MAX_WORDS];
    string suffixes[MAX_WORDS];

    string userFile;
    int order;
    int maxWords;
    int chainSize;


    cout << "Enter input file name: " << endl;
    cin >> userFile ;
    ifstream inputFile(userFile);

    cout << "Enter order (1, 2, or 3): " << endl;
    cin >> order;
    if(order > 3 || order < 1) {
        cout << "Please try again, order has to be 1-3" << endl;
        cin >> order;
    }

    cout << "Enter maximum number of words to generate: " << endl;
    cin >> maxWords ;
    if(maxWords <= order) {
        cout << "Sorry, order+1 training words are needed, try again. " << endl;
        cin >> maxWords;
    }

    int count = readWordsFromFile(userFile, words, maxWords);

    if(readWordsFromFile(userFile, words, maxWords) == -1) {
        cout << "File open failure." << endl;
    } 

   chainSize = buildMarkovChain(words, count, order, prefixes, suffixes, maxWords);

   // check chainSize > 0
   if(chainSize < 0){
        cout << "Error, chain size is less than 0. Try again." << endl;
   }
   // if input array is at capacity let user know
   if(maxWords > MAX_WORDS){
        cout << "Maximum capacity of 5000 words is reached. Any words after max capacity were ignored." << endl;
   }

    string output = generateText(prefixes, suffixes, chainSize, order, maxWords);

    
    
    cout << output << endl;

    


    return 0;
}
