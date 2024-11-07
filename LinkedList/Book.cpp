#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

const int NUM_PAGES = 10;

class Page {
public:
    string title;
    string content;

    Page() : title(""), content("") {}
};

class Book {
private:
    vector<Page> pages;

public:
    Book() : pages(NUM_PAGES) {}

    void addPage(int pageNum) {
        if (pageNum < 1 || pageNum > NUM_PAGES) {
            cout << "Invalid page number. Please enter a number between 1 and " << NUM_PAGES << ".\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter title for page " << pageNum << ": ";
        getline(cin, pages[pageNum - 1].title);

        cout << "Enter content for page " << pageNum << " (End with a line containing only 'END'):\n";
        string line;
        pages[pageNum - 1].content = "";
        while (getline(cin, line) && line != "END") {
            pages[pageNum - 1].content += line + "\n";
        }
    }

    void displayPage(int pageNum) const {
        if (pageNum < 1 || pageNum > NUM_PAGES) {
            cout << "Invalid page number. Please enter a number between 1 and " << NUM_PAGES << ".\n";
            return;
        }

        const Page& page = pages[pageNum - 1];
        cout << "\n--- Page " << pageNum << " ---\n";
        cout << "Title: " << page.title << "\n\n";
        cout << page.content << "\n";
    }

    void displayBook() const {
        for (int i = 0; i < NUM_PAGES; ++i) {
            displayPage(i + 1);
        }
    }
};

// It's a global function // 
void displayMenu() {
    cout << "\n--- Book Creator Menu ---\n";
    cout << "1. Add/Edit a page\n";
    cout << "2. Display a specific page\n";
    cout << "3. Display entire book\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Book myBook;
    int choice, pageNum;

    cout << "Welcome to the 10-Page Book Creator!\n";

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page number to add/edit (1-" << NUM_PAGES << "): ";
                cin >> pageNum;
                myBook.addPage(pageNum);
                break;
            case 2:
                cout << "Enter page number to display (1-" << NUM_PAGES << "): ";
                cin >> pageNum;
                myBook.displayPage(pageNum);
                break;
            case 3:
                myBook.displayBook();
                break;
            case 4:
                cout << "Thank you for using the Book Creator. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}