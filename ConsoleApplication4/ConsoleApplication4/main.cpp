#include "aeroflot.h"
#include "test.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// ������� ��� ����� ������ � ����������
void input�eroflots(AEROFLOT aeroflots[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cout << "\n������� ���������� � ������� #" << i + 1 << endl;
        cin >> aeroflots[i];
    }
}

// ������� ��� ������ ������� ���������� � ������������ ������
void outputWorkersWithExperience(const AEROFLOT aeroflots[], int arraySize, string thresholdYear) {
    bool found = false;
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < arraySize; ++i) {
        if (aeroflots[i].getnameAeroflot() == thresholdYear) {
            cout << "������, �������������� � " << thresholdYear << " ����� �����: " << aeroflots[i].getnomer() << endl;
            cout << "��� ������� �������: " << aeroflots[i].gettype() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "��� ���������� �� ������ ����� " << thresholdYear << " ���." << endl;
    }
}

class LogDuration {
public:
    LogDuration()
        : start(steady_clock::now())
    {}

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
    
        if (test() == 1) {
            std::cout << "\n����-����� �������� �������!" << std::endl;
        }
        else {
            std::cerr << "����-����� �� ��������!" << std::endl;
        }

        const int arraySize = 3;
        AEROFLOT aeroflots[arraySize];

        // ���� ������ � ����������
        input�eroflots(aeroflots, arraySize);
        {
            LogDuration input;
            // ���������� ���������� �� ��������
            sort(aeroflots, aeroflots + arraySize, compareAeroflots);
        }
        string thresholdYear;
        cout << "\n������� ����� ����������: ";
        cin >> thresholdYear;
        {
        LogDuration input;
        // ����� ������� ���������� � ������������ ������
        outputWorkersWithExperience(aeroflots, arraySize, thresholdYear);

        return 0;
    }
}