/*#include <iostream>
#include <map>
#include <algorithm>
#include <cassert>
#include <sstream>


class Book {
public:
    std::string author;
    std::string title;
    int year;
    int copies;

    Book(std::string author, std::string title, int year, int copies)
        : author(author), title(title), year(year), copies(copies) {}
};

class Library {
private:
    std::multimap<std::string, Book> books;

public:
    void addBook(const Book& book) {
        books.insert(std::make_pair(book.author, book));
    }

    void removeBook(const std::string& author, const std::string& title) {
        auto range = books.equal_range(author);
        for (auto it = range.first; it != range.second; ++it) {
            if (it->second.title == title) {
                books.erase(it);
                return;  // Важно вернуться после удаления, чтобы не использовать недействительный итератор
            }
        }
    }

    void displayBooksByAuthor() {
        std::cout << "Books ordered by author:\n";
        for (const auto& entry : books) {
            const Book& book = entry.second;
            std::cout << "Author: " << book.author << ", Title: " << book.title
                << ", Year: " << book.year << ", Copies: " << book.copies << "\n";
        }
    }

    void displayBooksByYear() {
        std::cout << "Books ordered by year:\n";
        std::multimap<int, Book> booksByYear;
        for (const auto& entry : books) {
            const Book& book = entry.second;
            booksByYear.insert(std::make_pair(book.year, book));
        }
        for (const auto& entry : booksByYear) {
            const Book& book = entry.second;
            std::cout << "Year: " << book.year << ", Author: " << book.author
                << ", Title: " << book.title << ", Copies: " << book.copies << "\n";
        }
    }
};


int main() {
    setlocale(LC_ALL, "Russian");


    Library library;

    // Пример добавления данных о книгах
    library.addBook(Book("Sanamyan O.A.", "Book1", 2000, 5));
    library.addBook(Book("Semenov G.A.", "Book2", 1995, 3));
    library.addBook(Book("Sarkisyan N.E.", "Book3", 2010, 2));
    library.addBook(Book("Verevkina E.S.", "Book4", 1800, 2));
    library.addBook(Book("Sanamyan O.A.", "Book5", 2510, 2));

    // Пример удаления данных о списываемых книгах
    library.removeBook("Sanamyan O.A.", "Book1");

    // Вывод сведений о книгах, упорядоченных по авторам
    library.displayBooksByAuthor();

    // Вывод сведений о книгах, упорядоченных по годам издания
    library.displayBooksByYear();

    return 0;
}*/