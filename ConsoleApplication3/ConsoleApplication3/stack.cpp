#include <iostream>
#include <vector>

using namespace std;

template <class Temp>//������ ����������
class Stack {//�������� ��� �������
private:
    vector<Temp> data;//������� ������ data, ������� ����� ������� �������� ���� Temp.
public:
    // ���������� �������� � ����
    void push(const Temp& value) {
        data.push_back(value);
    }

    // ���������� �������� �������� �� ����� 
    Temp pop() {
        if (empty()) {
            throw std::out_of_range("���� ����");//����������, ������� ��������� ��� ������� ������� � ��������� ��� ����������� ���������. 
        }
        Temp topElement = data.back();
        data.pop_back();
        return topElement;
    }

    // empty - �������� �� �������
    bool empty() const {
        return data.empty();
    }
};