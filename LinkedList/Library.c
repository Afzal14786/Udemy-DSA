#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100  // Max number of books that can be stored
#define FILENAME "books.txt" // Filename to save and load books from

typedef struct {
    char isbn[20];
    char title[100];
    char author[100];
    int year;
} Book;

void addBook(Book books[], int *count);
void displayBooks(const Book books[], int count);
int searchBookByISBN(const Book books[], int count, const char *isbn);
void updateBook(Book books[], int count, const char *isbn);
void deleteBook(Book books[], int *count, const char *isbn);
void saveToFile(const Book books[], int count, const char *filename);
void loadFromFile(Book books[], int *count, const char *filename);

void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Book list is full!\n");
        return;
    }

    printf("Enter ISBN: ");
    scanf("%s", books[*count].isbn);
    printf("Enter Title: ");
    getchar(); // to consume newline from previous input
    fgets(books[*count].title, 100, stdin);
    books[*count].title[strcspn(books[*count].title, "\n")] = 0; // remove newline
    printf("Enter Author: ");
    fgets(books[*count].author, 100, stdin);
    books[*count].author[strcspn(books[*count].author, "\n")] = 0;
    printf("Enter Publication Year: ");
    scanf("%d", &books[*count].year);

    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(const Book books[], int count) {
    if (count == 0) {
        printf("No books available!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("ISBN: %s, Title: %s, Author: %s, Year: %d\n",
               books[i].isbn, books[i].title, books[i].author, books[i].year);
    }
}

int searchBookByISBN(const Book books[], int count, const char *isbn) {
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            return i; // Book found, return its index
        }
    }
    return -1; // Book not found
}

void updateBook(Book books[], int count, const char *isbn) {
    int index = searchBookByISBN(books, count, isbn);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }

    printf("Enter new Title: ");
    getchar(); // to consume newline
    fgets(books[index].title, 100, stdin);
    books[index].title[strcspn(books[index].title, "\n")] = 0;
    printf("Enter new Author: ");
    fgets(books[index].author, 100, stdin);
    books[index].author[strcspn(books[index].author, "\n")] = 0;
    printf("Enter new Publication Year: ");
    scanf("%d", &books[index].year);

    printf("Book updated successfully!\n");
}

void deleteBook(Book books[], int *count, const char *isbn) {
    int index = searchBookByISBN(books, *count, isbn);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }

    for (int i = index; i < (*count) - 1; i++) {
        books[i] = books[i + 1]; // Shift all books one position left
    }
    (*count)--;
    printf("Book deleted successfully!\n");
}

void saveToFile(const Book books[], int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s,%d\n", books[i].isbn, books[i].title, books[i].author, books[i].year);
    }
    fclose(file);
    printf("Books saved to file successfully!\n");
}

void loadFromFile(Book books[], int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for loading!\n");
        return;
    }

    *count = 0;
    while (fscanf(file, "%[^,],%[^,],%[^,],%d\n", books[*count].isbn, books[*count].title,
                  books[*count].author, &books[*count].year) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Books loaded from file successfully!\n");
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;
    char isbn[20];

    loadFromFile(books, &count, FILENAME); // Load books from file at startup

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add a new book\n");
        printf("2. Display all books\n");
        printf("3. Search book by ISBN\n");
        printf("4. Update a book\n");
        printf("5. Delete a book\n");
        printf("6. Save books to file\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                printf("Enter ISBN to search: ");
                scanf("%s", isbn);
                int index = searchBookByISBN(books, count, isbn);
                if (index != -1) {
                    printf("Book found: ISBN: %s, Title: %s, Author: %s, Year: %d\n",
                           books[index].isbn, books[index].title, books[index].author, books[index].year);
                } else {
                    printf("Book not found!\n");
                }
                break;
            case 4:
                printf("Enter ISBN to update: ");
                scanf("%s", isbn);
                updateBook(books, count, isbn);
                break;
            case 5:
                printf("Enter ISBN to delete: ");
                scanf("%s", isbn);
                deleteBook(books, &count, isbn);
                break;
            case 6:
                saveToFile(books, count, FILENAME);
                break;
            case 7:
                saveToFile(books, count, FILENAME); // Save on exit
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
