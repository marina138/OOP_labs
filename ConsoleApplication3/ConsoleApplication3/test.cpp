#include "test.h"
#include <cassert>
#include "stack.cpp"

bool testStack() {
    // ������������ �������� � int
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    assert(intStack.pop() == 2);

    // ������������ �������� � double
    Stack<double> doubleStack;
    doubleStack.push(3.51);
    doubleStack.push(15.1);
    assert(doubleStack.pop() == 15.1);

    // ������������ �������� �� ��������
    Stack<string> stringStack;
    stringStack.push("�������");
    stringStack.push("�����");
    assert(stringStack.pop() == "�����");

    return true;
}