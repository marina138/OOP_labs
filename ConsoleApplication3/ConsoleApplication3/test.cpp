#include "test.h"
#include <cassert>
#include "stack.cpp"

bool testStack() {
    // Тестирование операций с int
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    assert(intStack.pop() == 2);

    // Тестирование операций с double
    Stack<double> doubleStack;
    doubleStack.push(3.51);
    doubleStack.push(15.1);
    assert(doubleStack.pop() == 15.1);

    // Тестирование операций со строками
    Stack<string> stringStack;
    stringStack.push("Маришка");
    stringStack.push("Класс");
    assert(stringStack.pop() == "Класс");

    return true;
}