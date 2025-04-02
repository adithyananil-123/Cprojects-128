#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[100];
} Book;

void addBook(Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    printf("Enter book title: ");
    scanf(" %[^\n]%*c", library[*count].title);
    printf("Enter book author: ");
    scanf(" %[^\n]%*c", library[*count].author);
    
    (*count)++;
    printf("Book added successfully!\n");
}

void searchBook(Book library[], int count) {
    char title[100];
    printf("Enter title of the book to search: ");
    scanf(" %[^\n]%*c", title);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Book found: Title: %s, Author: %s\n", library[i].title, library[i].author);
            return;
        }
    }
    printf("Book not found.\n");
}

void removeBook(Book library[], int *count) {
    char title[100];
    printf("Enter title of the book to remove: ");
    scanf(" %[^\n]%*c", title);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j + 1];
            }
            (*count)--;
            printf("Book removed successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void displayBooks(Book library[], int count) {
    if (count == 0) {
        printf("The library is empty.\n");
        return;
    }
    
    printf("Books in the library:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Author: %s\n", i + 1, library[i].title, library[i].author);
    }
}

int main() {
    Book library[MAX_BOOKS];
    int count = 0;
    int choice;
    
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Remove Book\n");
        printf("4. Display Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                searchBook(library, count);
                break;
            case 3:
                removeBook(library, &count);
                break;
            case 4:
                displayBooks(library, count);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
