//code for library book managment
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<graphics.h>
 struct Book {
    int id;
    char title[50];
    char author[50];
    int status; // 0 - Available, 1 - Issued
    struct Book* next;
};

Book* head = NULL;

void addBook() {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book ID: ");
    scanf("%d", &newBook->id);
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    newBook->status = 0;
    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
    printf("Book added successfully.\n");
}

void displayBooks() {
    Book* temp = head;
    printf("Book List:\n");
    while (temp != NULL) {
        printf("%d. %s by %s - ", temp->id, temp->title, temp->author);
        if (temp->status == 0) {
            printf("Available\n");
        } else {
            printf("Issued\n");
        }
        temp = temp->next;
    }
}
void issueBook() {
    int id;
    printf("Enter book ID to issue: ");
    scanf("%d", &id);
    Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id && temp->status == 0) {
            temp->status = 1;
            printf("Book issued successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Book not available or already issued.\n");
}
void returnBook() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    Book* temp = head;
    while (temp != NULL) {
        if (temp->id == id && temp->status == 1) {
            temp->status = 0;
            printf("Book returned successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Book not issued or invalid ID.\n");
}

int main() {
    int choice;
    while (1) {
        printf("Library Book Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}


