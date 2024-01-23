#include "test.h"
#include "aeroflot.h"
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int test() {
    AEROFLOT aeroflot("Ставрополь", "Грузовой", 156324);
    // Проверка вывода на экран
    cout << "Тест 1: Вывод на экран\n";
    cout << aeroflot << endl;

    // Проверка ввода с клавиатуры
    AEROFLOT workerInput;
    cout << "Тест 2: Ввод с клавиатуры\n";
    istringstream input("Москва\nПассажирский\12345\n");
    input >> workerInput;
    cout << "\nМосква\nПассажирский\12345\n";
    
    assert(workerInput.getnameAeroflot() == "Москва");
    assert(workerInput.gettype() == "Пассажирский");
    assert(workerInput.getnomer() == 12345);

    return 1;
}
