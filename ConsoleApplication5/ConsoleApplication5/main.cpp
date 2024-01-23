#include "sentence.h"
#include "test.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <chrono>

using namespace std;
using namespace chrono;

class LogDuration {
public:
    LogDuration()
        : start(steady_clock::now())
    {
    }

    ~LogDuration() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << duration_cast<milliseconds>(dur).count()
            << " ms" << endl;
    }
private:
    steady_clock::time_point start;
};

int main() {
    setlocale(LC_ALL, "Russian");
    {
    LogDuration input;
    if (testSentenceProcessing()) {
        cout << "Юнит-тесты пройдены успешно!" << endl;
    }
    else {
        cerr << "Юнит-тесты не пройдены!" << endl;
    }

    string filePath = "C:/Users/Oleg/Desktop/dada.txt";
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл." << endl;
        return 1;
    }

    vector<string> sentencesWithoutComma;
    string line;

    while (getline(inputFile, line)) {
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

    inputFile.close();

    for (const auto& sentence : sentencesWithoutComma) {
        cout << sentence << endl;
    }

    return 0;
    }
}
