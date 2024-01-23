#include "test.h"
#include "Library.h"

bool test() {
    
    Library library;
    library.addBook(Book("Sanamyan O.A.", "Book1", 2000, 5));

    const auto& books = library.getBooks();
    auto it = books.find("Sanamyan O.A.");
    if (it == books.end()) {
        return false;
    }

    library.removeBook("Sanamyan O.A.", "Book1");
    it = books.find("Sanamyan O.A.");
    if (it != books.end()) {
        return false;
    }

    return true;
}