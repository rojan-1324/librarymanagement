#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int isIssued;
};

void addBook() {
    struct Book b;
    FILE *fp = fopen("library.txt", "a");

    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter Book Author: ");
    scanf(" %[^\n]", b.author);
    b.isIssued = 0;

    fprintf(fp, "%d %s %s %d\n", b.id, b.title, b.author, b.isIssued);
    fclose(fp);

    printf("Book added successfully!\n");
}

void displayBooks() {
    struct Book b;
    FILE *fp = fopen("library.txt", "r");

    if (fp == NULL) {
        printf("No books found.\n");
        return;
    }

    printf("\nBooks in Library:\n");
    while (fscanf(fp, "%d %s %s %d", &b.id, b.title, b.author, &b.isIssued) != EOF) {
        printf("ID: %d | Title: %s | Author: %s | Status: %s\n",
               b.id, b.title, b.author, b.isIssued ? "Issued" : "Available");
    }

    fclose(fp);
}

void issueBook() {
    struct Book b;
    int id, found = 0;
    FILE *fp = fopen("library.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No books found.\n");
        return;
    }

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d", &b.id, b.title, b.author, &b.isIssued) != EOF) {
        if (b.id == id) {
            found = 1;
            if (b.isIssued) {
                printf("Book already issued.\n");
            } else {
                b.isIssued = 1;
                printf("Book issued successfully!\n");
            }
        }
        fprintf(temp, "%d %s %s %d\n", b.id, b.title, b.author, b.isIssued);
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(fp);
    fclose(temp);

    remove("library.txt");
    rename("temp.txt", "library.txt");
}

void returnBook() {
    struct Book b;
    int id, found = 0;
    FILE *fp = fopen("library.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No books found.\n");
        return;
    }

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d", &b.id, b.title, b.author, &b.isIssued) != EOF) {
        if (b.id == id) {
            found = 1;
            if (b.isIssued) {
                b.isIssued = 0;
                printf("Book returned successfully!\n");
            } else {
                printf("Book was not issued.\n");
            }
        }
        fprintf(temp, "%d %s %s %d\n", b.id, b.title, b.author, b.isIssued);
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(fp);
    fclose(temp);

    remove("library.txt");
    rename("temp.txt", "library.txt");
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Library Management System ===\n");
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
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
