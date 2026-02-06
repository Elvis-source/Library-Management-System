#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    bool borrowed;

    Book(int i, string t) {
        id = i;
        title = t;
        borrowed = false;
    }
};

class User {
public:
    int userId;
    string name;
    int borrowedBook;

    User(int id, string n) {
        userId = id;
        name = n;
        borrowedBook = -1;
    }
};

class Library {
public:
    vector<Book> books;
    vector<User> users;

    void addBook(int id, string title) {
        books.push_back(Book(id, title));
    }

    void addUser(int id, string name) {
        users.push_back(User(id, name));
    }

    void borrowBook(int userId, int bookId) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == bookId && !books[i].borrowed) {
                books[i].borrowed = true;
         for (int j = 0; j < users.size(); j++) {
             if (users[j].userId == userId) {
                 users[j].borrowedBook = bookId;
                cout << "Book borrowed successfully\n";
             return;
        }
        }
        }
        }
        cout << "Borrowing failed\n";
    }

    void returnBook(int userId) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].userId == userId) {
                int bookId = users[i].borrowedBook;
        for (int j = 0; j < books.size(); j++) {
            if (books[j].id == bookId) {
                books[j].borrowed = false;
                users[i].borrowedBook = -1;
               cout << "Book returned\n";
               return;
    }
    } 
    }
    }
        cout << "Return failed\n";
    }
};

int main() {
    Library lib;

    lib.addBook(1, "C++ Basics");
    lib.addBook(2, "OOP Concepts");

    lib.addUser(101, "John");

    lib.borrowBook(101, 1);   // positive test
    lib.borrowBook(101, 1);   // negative test
    lib.returnBook(101);      // return test

    return 0;
}
