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
            cout << "Юнит-тесты пройдены успешно!" << endl;
        }
        else {
            cerr << "Юнит-тесты не пройдены!" << endl;
        }

        Library library;
        library.loadFromFile("books.txt");
        int choice;
        do {
            cout << "\nМеню:\n";
            cout << "1. Добавить данные о книгах\n";
            cout << "2. Удалить данные о списываемых книгах\n";
            cout << "3. Вывести сведения о книгах по авторам\n";
            cout << "4. Вывести сведения о книгах по годам издания\n";
            cout << "5. Сохранить данные в файл\n";
            cout << "0. Выйти из программы\n";

            cout << "\nВыберите действие (введите номер): \n";
            cin >> choice;

            switch (choice) {
            case 1: {
                string author, title;
                int year, copies;
                cout << "Введите информацию о книге:\n";
                cout << "Автор: ";
                cin.ignore();
                getline(cin, author);
                cout << "Название: ";
                getline(cin, title);
                while (true) {
                    cout << "Год издания: ";
                    if (cin >> year) {
                        break;
                    }
                    else {
                        cerr << "Ошибка ввода! Введите целочисленное значение." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                while (true) {
                    cout << "Количество копий: ";
                    if (cin >> copies) {
                        break;
                    }
                    else {
                        cerr << "Ошибка ввода! Введите целочисленное значение." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                library.addBook(Book(author, title, year, copies));
                break;
            }
            case 2: {
                string author, title;
                cout << "Введите информацию о книге для удаления:\n";
                cout << "Автор: ";
                cin.ignore();
                getline(cin, author);
                cout << "Название: ";
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
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный ввод. Попробуйте еще раз.\n";
            }
        } while (choice != 0);

        return 0;
}
