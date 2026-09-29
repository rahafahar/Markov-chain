#ifndef MARKOV_H
#define MARKOV_H
#include <string>

//function1: joins words into one string including spaces, used for orders > 1
std::string joinWords(const std::string words[], int startIndex, int count);

/* func2: Opens a text file and reads whitespace-separated words into the array, stopping at maxWords.
Punctuation and capitalization stay attached to the words. Additional words beyond the capacity are not used. */
int readWordsFromFile(std::string filename, std::string words[], int maxWords);

/* function 3: scans through all the words and records "what comes after what.
 This function scans through all the words and records "what comes after what.*/
int buildMarkovChain(const std::string words[], int numWords, int order, std::string prefixes[], std::string suffixes[], int maxChainSize);

/*func4:  Given a prefix like "the cat", this function finds ALL the entries in the chain that have that prefix, 
then randomly picks one of the corresponding suffixes. It's like flipping through your flashcards,
finding all the ones with "the cat" on the front, and randomly picking one to see what's on the back.*/
std::string getRandomSuffix(const std::string prefixes[], const std::string suffixes[],  int chainSize, std::string currentPrefix);

/*funct5: This function just picks a random prefix from your chain to use as the starting point for text generation. It's like closing your
eyes and pointing at a random flashcard to start with.*/
std::string getRandomPrefix(const std::string prefixes[], int chainSize);


/*: This is the fun one! It "walks" the Markov chain to generate new text. 
It picks a random starting point, then keeps asking "what word comes next?" over and over, building up a sentence word by word.*/
std::string generateText(const std::string prefixes[], const std::string suffixes[], int chainSize, int order, int numWords);



#endif