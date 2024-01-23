#include "Library.h"
#include "test.h"
#include <iostream>
#include <chrono>

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

        if (test()) {
            cout << "����-����� �������� �������!" << endl;
        }
        else {
            cerr << "����-����� �� ��������!" << endl;
        }

        Library library;
        library.loadFromFile("books.txt");
        int choice;
        do {
            cout << "\n����:\n";
            cout << "1. �������� ������ � ������\n";
            cout << "2. ������� ������ � ����������� ������\n";
            cout << "3. ������� �������� � ������ �� �������\n";
            cout << "4. ������� �������� � ������ �� ����� �������\n";
            cout << "5. ��������� ������ � ����\n";
            cout << "0. ����� �� ���������\n";

            cout << "\n�������� �������� (������� �����): \n";
            cin >> choice;

            switch (choice) {
            case 1: {
                string author, title;
                int year, copies;
                cout << "������� ���������� � �����:\n";
                cout << "�����: ";
                cin.ignore();
                getline(cin, author);
                cout << "��������: ";
                getline(cin, title);
                while (true) {
                    cout << "��� �������: ";
                    if (cin >> year) {
                        break;
                    }
                    else {
                        cerr << "������ �����! ������� ������������� ��������." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                while (true) {
                    cout << "���������� �����: ";
                    if (cin >> copies) {
                        break;
                    }
                    else {
                        cerr << "������ �����! ������� ������������� ��������." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                library.addBook(Book(author, title, year, copies));
                break;
            }
            case 2: {
                string author, title;
                cout << "������� ���������� � ����� ��� ��������:\n";
                cout << "�����: ";
                cin.ignore();
                getline(cin, author);
                cout << "��������: ";
                getline(cin, title);

                library.removeBook(author, title);
                break;
            }
            case 3:
            {
                LogDuration input;
                library.displayBooksByAuthor();
                break;
            }
            case 4:
            {
                LogDuration input;
                library.displayBooksByYear();
                break;
            }
            case 5:
                library.saveToFile("books.txt");
                break;
            case 0:
                cout << "����� �� ���������.\n";
                break;
            default:
                cout << "�������� ����. ���������� ��� ���.\n";
            }
        } while (choice != 0);

        return 0;
}
