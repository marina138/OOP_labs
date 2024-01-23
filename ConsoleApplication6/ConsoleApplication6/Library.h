#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <map>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <fstream>

using namespace std;

class Book {
public:
    string author;
    string title;
    int year;
    int copies;

    Book(string author, string title, int year, int copies)
        : author(author), title(title), year(year), copies(copies) {}
};

class Library {
private:
    multimap<string, Book> books;

public:
    void addBook(const Book& book);
    void removeBook(const string& author, const string& title);
    void displayBooksByAuthor();
    void displayBooksByYear();
    const multimap<string, Book>& getBooks() const;

    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};

#endif