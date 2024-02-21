#include <iostream>
#include <string>
using namespace std;

class BookManagement {
private:
    struct Node {
        int id;
        string title, author, category;
        Node* next;
    };
public:
    Node* head = NULL;
    void insertBook();
    void menu();
    void searchBook();
    void deleteBook();
    void showBooks();
};

void BookManagement::menu() {
    int choice;
    while (true) {
        cout << "\n\t______Book Management System______";
        cout << "\n1\tAdd Book";
        cout << "\n2\tSearch Book";
        cout << "\n3\tDelete Book";
        cout << "\n4\tShow Books";
        cout << "\n5\tExit" << endl;

        cout << "Enter Your Choice:";
        cin >> choice;

        switch (choice) {
        case 1:
            insertBook();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            deleteBook();
            break;
        case 4:
            showBooks();
            break;
        case 5:
            return;
        default:
            cout << "Invalid Choice!" << endl;

        }
    }
}

void BookManagement::insertBook() {
    Node* newBook = new Node;

    cout << "\nEnter Book ID:";
    cin >> newBook->id;

    cout << "Enter Book Title:";
    cin.ignore();
    getline(cin, newBook->title);

    cout << "Enter Book Author:";
    getline(cin, newBook->author);

    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    }
    else {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newBook;
    }
    cout << "\nNew Book Inserted Successfully!" << endl;
}

void BookManagement::searchBook() {
    int bookId;
    cout << "\nEnter Book ID:";
    cin >> bookId;

    Node* ptr = head;
    while (ptr != NULL) {
        if (bookId == ptr->id) {
            cout << "\nBook ID:" << ptr->id << endl;
            cout << "Book Title:" << ptr->title << endl;
            return;
        }
        ptr = ptr->next;
    }
    cout << "\nBook not found!" << endl;
}

void BookManagement::deleteBook() {
    int bookId;
    cout << "\nEnter Book ID:";
    cin >> bookId;

    if (head == NULL) {
        cout << "\nBook List is empty!" << endl;
        return;
    }
    if (bookId == head->id) {
        Node* ptr = head;
        head = head->next;
        delete ptr;
        cout << "\nBook Record Deleted Successfully!" << endl;
        return;
    }
    Node* prev = head;
    Node* curr = head->next;
    while (curr != NULL) {
        if (curr->id == bookId) {
            prev->next = curr->next;
            delete curr;
            cout << "\nBook Record Deleted Successfully!" << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "\nBook Not Found!" << endl;
}

void BookManagement::showBooks() {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << "\nBook ID:" << ptr->id << endl;
        cout << "Book Title:" << ptr->title << endl;
        cout << "Book Author:" << ptr->author << endl;
        ptr = ptr->next;
    }
}

int main() {
    BookManagement bookManagement;
    bookManagement.menu();
    return 0;
}
