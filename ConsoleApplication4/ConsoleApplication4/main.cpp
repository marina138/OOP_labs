#include "aeroflot.h"
#include "test.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Функция для ввода данных о работниках
void inputАeroflots(AEROFLOT aeroflots[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cout << "\nВведите информацию о самолёте #" << i + 1 << endl;
        cin >> aeroflots[i];
    }
}

// Функция для вывода фамилий работников с определенным стажем
void outputWorkersWithExperience(const AEROFLOT aeroflots[], int arraySize, string thresholdYear) {
    bool found = false;
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < arraySize; ++i) {
        if (aeroflots[i].getnameAeroflot() == thresholdYear) {
            cout << "Самолёт, отправляющийся в " << thresholdYear << " имеет номер: " << aeroflots[i].getnomer() << endl;
            cout << "Тип данного самолёта: " << aeroflots[i].gettype() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Нет работников со стажем более " << thresholdYear << " лет." << endl;
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
            std::cout << "\nЮнит-тесты пройдены успешно!" << std::endl;
        }
        else {
            std::cerr << "Юнит-тесты не пройдены!" << std::endl;
        }

        const int arraySize = 3;
        AEROFLOT aeroflots[arraySize];

        // Ввод данных о работниках
        inputАeroflots(aeroflots, arraySize);
        {
            LogDuration input;
            // Сортировка работников по алфавиту
            sort(aeroflots, aeroflots + arraySize, compareAeroflots);
        }
        string thresholdYear;
        cout << "\nВведите пункт назначения: ";
        cin >> thresholdYear;
        {
        LogDuration input;
        // Вывод фамилий работников с определенным стажем
        outputWorkersWithExperience(aeroflots, arraySize, thresholdYear);

        return 0;
    }
}