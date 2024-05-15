#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

// In This Project Her Is The Importante Function
/*
    - Add A Book --> Add A Lot Of Information
    - Search About A Book
    - Delete A Book
    - Delete All Books
    - Edit Some Information About The Book [id, name, author]
    - Show Books
*/

// Strcture
typedef struct Book {
    int id;
    char book_name[50];
    char author_name[50];
    struct Book *next;
} Book;


// Start Add Function
void create_book(Book ***book) {
    Book *new_book = (Book *) malloc(sizeof(Book));
    printf("Enter Name Of The Book : "); getchar();
    scanf("%[^\n]", &new_book->book_name);
    printf("Enter The Id Of The Book : ");
    scanf("%d", &new_book->id); getchar();
    printf("Enter The Author Name : ");
    scanf("%[^\n]", &new_book->author_name);
    new_book->next = **book;
    **book = new_book;
}

void add_books(Book **book) {
    int book_nbr;
    printf("Enter Number Of Books : ");
    scanf("%d", &book_nbr);
    for (int i = 0; i < book_nbr; i++) {
        printf("\n-- Book %d\n", i + 1);
        create_book(&book);
    }
}
// End Add Function


// Start Edit Function
void edit_bookName(Book *book) {
    Book *temp = book;
    char book_name[50];
    printf("Enter The Name Of The Book : "); getchar();
    gets(book_name);
    // Find The Book
    while (1) {
        if (strcmp(temp->book_name, book_name) == 0) {
            char new_book_name[50];
            printf("Enter The New Name : ");
            gets(new_book_name);
            strcpy(temp->book_name, new_book_name); break;
        }
        temp = temp->next;
        if (temp == NULL) {
            printf("\t\t\t\t\t We Can Found This Book\n"); break;
        }
    }
}

void edit_authorName(Book *book) {
    Book *temp = book;
    char author_name[50];
    printf("Enter The Name Of The Author : "); getchar();
    gets(author_name);
    // Find The Book
    while (1) {
        if (strcmp(temp->author_name, author_name) == 0) {
            char new_author_name[50];
            printf("Enter The New Name : ");
            gets(new_author_name);
            strcpy(temp->author_name, new_author_name); break;
        }
        temp = temp->next;
        if (temp == NULL) {
            printf("\t\t\t\t\t We Can Found This Book\n"); break;
        }
    }
}

void edit_id(Book *book) {
    Book *temp = book;
    int id;
    printf("Enter The Id Of The Book : "); getchar();
    scanf("%d", &id);
    // Find The Book
    while (1) {
        if (temp->id == id) {
            int new_id;
            printf("Enter The New Id : ");
            gets(new_id);
            temp->id = new_id; break;
        }
        temp = temp->next;
        if (temp == NULL) {
            printf("\t\t\t\t\t We Can Found This Book\n"); break;
        }
    }
}

void edit_books(Book *book) {
    Book *temp = book;
    // Choose Editing
    int choose_edit;
    printf("\t\t\t\t\t[1]: Edit Using Book Name\n");
    printf("\t\t\t\t\t[2]: Edit Using Author Name\n");
    printf("\t\t\t\t\t[3]: Edit Using Id Name\n");
    printf("Choose Method For Editing : ");
    scanf("%d", &choose_edit);
    switch(choose_edit) {
        case 1: {
            edit_bookName(book); break;
        }
        case 2: {
            edit_authorName(book); break;
        }
        case 3: {
            edit_id(book); break;
        }
        default: break;
    }
}
// End Edit Function


// Start Search Function
int search_bookName(Book *book) {
    int index = 0;
    char book_name[50]; getchar();
    printf("Enter The Name Of Book : ");
    gets(book_name);
    // Start Searching About The Books
    Book *temp = book;
    while (temp != NULL) {
        if (strcmp(book_name, temp->book_name) == 0) {
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", book->id, book->book_name, book->author_name);
            return index;
        }
        index++; temp = temp->next;
    }
    printf("\t\t\t\t\tWe Can Not Found %s At List\n", book_name);
    return -1;
}

int search_authorName(Book *book) {
    int index = 0;
    char author_name[50]; getchar();
    printf("Enter The Author Of Book : ");
    gets(author_name);
    // scanf("%[^\n]s", author_name); author_name[49] = '\0';
    Book *temp = book;
    while (temp != NULL) {
        if (strcmp(author_name, temp->author_name) == 0) {
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", book->id, book->book_name, book->author_name);
            return index;
        }
        index++; temp = temp->next;
    }
    printf("\t\t\t\t\tWe Can Not Found %s At List\n", author_name);
    return -1;
}

int search_id(Book *book) {
    int id, index = 0; getchar();
    printf("Enter The Id Of Book : ");
    scanf("%d", &id);
    // Start Searching About The Books
    Book *temp = book;
    while (temp != NULL) {
        if (id == temp->id) {
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", book->id, book->book_name, book->author_name);
            return index;
        }
        index++; temp = temp->next;
    }
    printf("\t\t\t\t\tWe Can Not Found %s At List\n", id);
    return -1;
}

int search_books(Book *book) {
    int choose_search;
    printf("\t\t\t\t\t[1]: Search Using Book Name\n");
    printf("\t\t\t\t\t[2]: Search Using Author Name\n");
    printf("\t\t\t\t\t[3]: Search Using Id Name\n");
    printf("Choose Method For Searching : ");
    scanf("%d", &choose_search);
    switch(choose_search) {
        case 1: {
            search_bookName(book); break;
        }
        case 2: {
            search_authorName(book); break;
        }
        case 3: {
            search_id(book); break;
        }
        default: break;
    }
}
// End Search Function


// Start Delete Function
void delete_bookName(Book ***book) {
    Book *temp = **book;
    char book_name[50];
    printf("Enter The Name Of The Book : "); getchar();
    gets(book_name);
    // Find The Book
    while (1) {
        if (strcmp(temp->book_name, book_name) == 0) {
            Book *p = temp;
            if (strcmp((**book)->book_name, book_name) == 0) {
                **book = temp->next;
            }
            temp = temp->next;
            free(p);
            break;
        }
        temp = temp->next;
        if (temp == NULL) {
            printf("\t\t\t\t\t We Can Found This Book\n"); break;
        }
    }
}


void delete_authorName(Book *book) {

}

void delete_id(Book *book) {

}

void delete_books(Book **book) {
    // Choose Deleting
    int choose_delete;
    printf("\t\t\t\t\t[1]: Deleting Using Book Name\n");
    printf("\t\t\t\t\t[2]: Deleting Using Author Name\n");
    printf("\t\t\t\t\t[3]: Deleting Using Id Name\n");
    printf("Choose Method For Editing : ");
    scanf("%d", &choose_delete);
    switch(choose_delete) {
        case 1: {
            delete_bookName(book); break;
        }
        case 2: {
            delete_authorName(&book); break;
        }
        case 3: {
            delete_id(&book); break;
        }
        default: break;
    }
}
// End Delete Function


// Start Display Function

void dispay_books(Book *book) {
    if (book == NULL) printf("\nNo Book Exit\n");
    else {
        Book *temp = book;
        while (temp != NULL) {
            printf("%d %s %s\n", temp->id, temp->book_name, temp->author_name);
            temp = temp->next;
        }
    }
}

// End Display Function

/*
// Start Trach Function
void trach(Book *info_book, int nbr_of_book) {
    printf("Trach Function");
}
// End Trach Function
*/


int main() {
    int choose;
    Book *book = NULL;
    printf("[1]: Add A Book\n");
    printf("[2]: Search About Book\n");
    printf("[3]: Delete A Book\n");
    printf("[4]: Edit Some Information\n");
    printf("[5]: Display The Books\n");
    printf("[6]: Display The Trach\n");
    printf("[7]: Exit\n");
    do {
        printf("\n--------------------------------\n");
        printf("Enter An Operation : ");
        scanf("%d", &choose);
        choose = (int) choose;
        switch(choose) {
            case 1: {
                add_books(&book); break;
            }
            case 2: {
                search_books(book); break;
            }
            case 3: {
                delete_books(&book); break;
            }
            case 4: {
                edit_books(book); break;
            }
            case 5: {
                dispay_books(book); break;
            }
            case 6: {
                // trach(book);
                break;
            }
            default: break;
        }
    } while (choose < 6 && choose > 0);
    return 0;
}














