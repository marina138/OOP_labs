#include "sentence.h"
#include "test.h"
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;

bool testSentenceProcessing() {
    stringstream input("Hello, world! How are you? How feeling you?");

    vector<string> sentencesWithoutComma;


    string line;
    while (getline(input, line)) {
        string currentSentence;
        for (char c : line) {
            currentSentence += c;
            if (isEndOfSentence(c)) {
                if (!containsComma(currentSentence)) {
                    sentencesWithoutComma.push_back(currentSentence);
                }
                currentSentence.clear();
            }
        }
    }

    
    assert(sentencesWithoutComma.size() == 2);
    assert(sentencesWithoutComma[0] == " How are you?");
    assert(sentencesWithoutComma[1] == " How feeling you?");
    return true;
}