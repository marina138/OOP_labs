#include "sentence.h"

bool containsComma(const std::string& sentence) {
    return std::any_of(sentence.begin(), sentence.end(), [](char c) {
        return c == ',';
        });
}

bool isEndOfSentence(char c) {
    return c == '.' || c == '?' || c == '!';
}