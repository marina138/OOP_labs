#include <iostream>
#include <vector>

using namespace std;

template <class Temp>//список параметров
class Stack {//хрянятся как тарелки
private:
    vector<Temp> data;//создает вектор data, который будет хранить элементы типа Temp.
public:
    // Добавление элемента в стек
    void push(const Temp& value) {
        data.push_back(value);
    }

    // Извлечение верхнего элемента из стека 
    Temp pop() {
        if (empty()) {
            throw std::out_of_range("Стек пуст");//исключение, которое возникает при попытке доступа к элементам вне допустимого диапазона. 
        }
        Temp topElement = data.back();
        data.pop_back();
        return topElement;
    }

    // empty - Проверка на пустоту
    bool empty() const {
        return data.empty();
    }
};