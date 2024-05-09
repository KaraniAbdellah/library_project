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
} Book;


// Start Add Function
int add_books(Book *info_book, int nbr_of_book) {
    int book_nbr;
    printf("Enter Number Of Books : ");
    scanf("%d", &book_nbr);
    for (int i = 0; i < book_nbr; i++) {
        printf("\n-- Book %d\n", i + 1);
        printf("Enter Name Of The Book : "); getchar();
        scanf("%[^\n]s", &info_book[nbr_of_book + i].book_name);
        printf("Enter The Id Of The Book : ");
        scanf("%d", &info_book[nbr_of_book + i].id); getchar();
        printf("Enter The Author Name : ");
        scanf("%[^\n]s", &info_book[nbr_of_book + i].author_name);
    }
    nbr_of_book += book_nbr;
    return nbr_of_book; // Start of Filing The Data
}
// End Add Function

// Start Edit Function
void edit_bookName(Book *info_book, int pos) {

}

void edit_authorName(Book *info_book, int pos) {

}

void edit_id(Book *info_book, int pos) {

}

void edit_books(Book *info_book, int nbr_of_book) {
    int choose_edit;
    char book_edit_cur[50], book_edit_new[50];
    printf("\t\t\t\t\t[1]: Edit Book Name\n");
    printf("\t\t\t\t\t[2]: Edit Author Name\n");
    printf("\t\t\t\t\t[3]: Edit Id Name\n");
    printf("Choose Method For Editing : ");
    scanf("%d", &choose_edit); getchar();
    int pos = search_books(info_book, nbr_of_book);
    if (pos != -1) {
        switch(choose_edit) {
            case 1: {
                edit_bookName(info_book, pos); break;
            }
            case 2: {
                edit_authorName(info_book, pos); break;
            }
            case 3: {
                edit_id(info_book, pos); break;
            }
            default: break;
        }
    }

}
// End Edit Function


// Start Search Function
int search_bookName(Book *info_book, int nbr_of_book) {
    char book_name[50]; getchar();
    printf("Enter The Name Of Book : ");
    scanf("%[^\n]s", book_name); book_name[49] = '\0';
    // Start Searching About The Books
    for (int i = 0; i < nbr_of_book; i++) {
        if (strcmp(book_name, info_book[i].book_name) == 0) {
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", info_book[i].id, info_book[i].book_name, info_book[i].author_name);
            return i;
        }
    }
    printf("\t\t\t\t\tWe Do Not Fount %s At List", book_name[50]);
    return -1;
}

int search_authorName(Book *info_book, int nbr_of_book) {
    char author_name[50]; getchar();
    printf("Enter The Author Of Book : ");
    scanf("%[^\n]s", author_name); author_name[49] = '\0';
    // Start Searching About The Books
    for (int i = 0; i < nbr_of_book; i++) {
        if (strcmp(author_name, info_book[i].author_name) == 0) {
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", info_book[i].id, info_book[i].book_name, info_book[i].author_name);
            return i;
        }
    }
    printf("\t\t\t\t\tWe Do Not Fount %s At List", author_name[50]);
    return -1;
}

int search_id(Book *info_book, int nbr_of_book) {
    int id; getchar();
    printf("Enter The Id Of Book : ");
    scanf("%d", &id);
    // Start Searching About The Books
    for (int i = 0; i < nbr_of_book; i++) {
        if (id == info_book[i].id) {
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", info_book[i].id, info_book[i].book_name, info_book[i].author_name);
            return i;
        }
    }
    printf("\t\t\t\t\tWe Do Not Fount %d At List", id);
    return -1;
}

int search_books(Book *info_book, int nbr_of_book) {
    int choose_search, pos;
    printf("\t\t\t\t\t[1]: Search Using Book Name\n");
    printf("\t\t\t\t\t[2]: Search Using Author Name\n");
    printf("\t\t\t\t\t[3]: Search Using Id Name\n");
    printf("Choose Method For Searching : ");
    scanf("%d", &choose_search);
    switch(choose_search) {
        case 1: {
            pos = search_bookName(info_book, nbr_of_book); break;
        }
        case 2: {
            pos = search_authorName(info_book, nbr_of_book); break;
        }
        case 3: {
            pos = search_id(info_book, nbr_of_book); break;
        }
        default: break;
    }
    return pos; // For Edit Functions
}
// End Search Function

// Start Delete Function
void delete_books(Book *info_book, int nbr_of_book) {
    printf("Hello 1");
}
// End Delete Function


// Start Display Function
void dispay_books(Book *info_book, int nbr_of_book) {
    for (int i = 0; i < nbr_of_book; i++) {
        printf("\nBOOK %d : \n", i + 1);
        printf("%d %s %s", info_book[i].id, info_book[i].author_name, info_book[i].book_name);
    }
}
// End Display Function

// Start Trach Function
void trach(Book *info_book, int nbr_of_book) {
    printf("Trach Function");
}
// End Trach Function



int main() {
    int choose, nbr_of_book = 0;
    Book info_book[50];
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
        switch(choose) {
            case 1: {
                nbr_of_book = add_books(info_book, nbr_of_book); break;
            }
            case 2: {
                search_books(info_book, nbr_of_book); break;
            }
            case 3: {
                delete_books(info_book, nbr_of_book); break;
            }
            case 4: {
                edit_books(info_book, nbr_of_book); break;
            }
            case 5: {
                dispay_books(info_book, nbr_of_book); break;
            }
            case 6: {
                trach(info_book, nbr_of_book);
                break;
            }
            default: break;
        }
    } while (choose < 6 && choose > 0);
    return 0;
}














