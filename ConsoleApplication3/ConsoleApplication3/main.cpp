#include <iostream>
#include <sstream>
#include <chrono>
#include "stack.cpp"
#include "test.h"

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
        if (testStack()) {
            cout << "����-����� �������� �������!" << endl;
        }
        else {
            cerr << "����-����� �� ��������!" << endl;
        }
        try {
            // ������������� ���������� ������ Stack � ������ int, double, string
            Stack<int> intStack;
            intStack.push(1);
            intStack.push(2);
            cout << "��������� �� intStack: " << intStack.pop() << endl;

            Stack<double> doubleStack;
            doubleStack.push(3.51);
            doubleStack.push(15.1);
            cout << "��������� �� doubleStack: " << doubleStack.pop() << endl;

            Stack<string> stringStack;
            stringStack.push("�������");
            stringStack.push("�����");
            cout << "��������� �� stringStack: " << stringStack.pop() << endl;

        }
        catch (const exception& e) {
            cerr << "����������: " << e.what() << endl;
        }

        return 0;
    }
}