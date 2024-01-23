#include "Library.h"

using namespace std;

void Library::addBook(const Book& book) {
    books.insert(make_pair(book.author, book));
}

void Library::removeBook(const string& author, const string& title) {
    auto range = books.equal_range(author);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.title == title) {
            books.erase(it);
            cout << "Книга успешно удалена.\n";
            return;
        }
    }

    cerr << "Ошибка: Книга не найдена для удаления.\n";
}

void Library::displayBooksByAuthor() {
    cout << "Books ordered by author:\n";
    for (const auto& entry : books) {
        const Book& book = entry.second;
        cout << "Author: " << book.author << ", Title: " << book.title
            << ", Year: " << book.year << ", Copies: " << book.copies << "\n";
    }
}

void Library::displayBooksByYear() {
    cout << "Books ordered by year:\n";
    multimap<int, Book> booksByYear;
    for (const auto& entry : books) {
        const Book& book = entry.second;
        booksByYear.insert(make_pair(book.year, book));
    }
    for (const auto& entry : booksByYear) {
        const Book& book = entry.second;
        cout << "Year: " << book.year << ", Author: " << book.author
            << ", Title: " << book.title << ", Copies: " << book.copies << "\n";
    }
}

const multimap<string, Book>& Library::getBooks() const {
    return books;
}

void Library::saveToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : books) {
            const Book& book = entry.second;
            file << book.author << ',' << book.title << ',' << book.year << ',' << book.copies << '\n';
        }
        file.close();
        cout << "Данные сохранены в файл.\n";
    }
    else {
        cerr << "Не удалось открыть файл для сохранения данных.\n";
    }
}

void Library::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        books.clear();

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string author, title;
            int year, copies;
            char comma;
            if (getline(ss, author, ',') &&
                getline(ss, title, ',') &&
                ss >> year >> comma &&
                ss >> copies) {
                addBook(Book(author, title, year, copies));
            }
            else {
                cerr << "Ошибка при чтении данных из файла.\n";
            }
        }

        file.close();
        cout << "Данные загружены из файла.\n";
    }
    else {
        cerr << "Не удалось открыть файл для загрузки данных.\n";
    }
}