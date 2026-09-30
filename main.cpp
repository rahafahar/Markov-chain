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

    return 0;
}
