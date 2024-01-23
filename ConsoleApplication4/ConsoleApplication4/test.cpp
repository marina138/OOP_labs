#include "test.h"
#include "aeroflot.h"
#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int test() {
    AEROFLOT aeroflot("����������", "��������", 156324);
    // �������� ������ �� �����
    cout << "���� 1: ����� �� �����\n";
    cout << aeroflot << endl;

    // �������� ����� � ����������
    AEROFLOT workerInput;
    cout << "���� 2: ���� � ����������\n";
    istringstream input("������\n������������\12345\n");
    input >> workerInput;
    cout << "\n������\n������������\12345\n";
    
    assert(workerInput.getnameAeroflot() == "������");
    assert(workerInput.gettype() == "������������");
    assert(workerInput.getnomer() == 12345);

    return 1;
}
