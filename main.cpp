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

    return 0;
}
