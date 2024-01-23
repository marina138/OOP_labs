/*#include <iostream>
#include <vector>
#include <cassert>

template <class Temp>
class Stack {
private:
    std::vector<Temp> data;
public:
    // Добавление элемента в стек
    void push(const Temp& value) {
        data.push_back(value);
    }

    // Извлечение элемента из стека 
    Temp pop() {
        if (empty()) {
            throw std::out_of_range("Стек пуст");
        }
        Temp topElement = data.back();
        data.pop_back();
        return topElement;
    }

    // Проверка на пустоту
    bool empty() const {
        return data.empty();
    }
};



int main() {
    setlocale(LC_ALL, "Russian");

    testStack();
    std::cout << "Все тесты пройдены успешно." << std::endl;

    try {
        // Использование шаблонного класса Stack с типами int, double, std::string
        Stack<int> intStack;
        intStack.push(1);
        intStack.push(2);
        std::cout << "Извлечено из intStack: " << intStack.pop() << std::endl;

        Stack<double> doubleStack;
        doubleStack.push(3.14);
        doubleStack.push(2.71);
        std::cout << "Извлечено из doubleStack: " << doubleStack.pop() << std::endl;

        Stack<std::string> stringStack;
        stringStack.push("Привет");
        stringStack.push("Мир");
        std::cout << "Извлечено из stringStack: " << stringStack.pop() << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}*/