#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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




// Start Function
void add_books(Book *info_book) {
    int book_nbr;
    printf("Enter Number Of Books : ");
    scanf("%d", &book_nbr);
    info_book = realloc(info_book, book_nbr * sizeof(Book));
    for (int i = 0; i < book_nbr; i++) {
        printf("\n-- Book %d\n", i + 1);
        printf("Enter Name Of The Book : "); getchar();
        scanf("%[^\n]s", &info_book[i].book_name);
        printf("Enter The Id Of The Book : ");
        scanf("%d", &info_book[i].id); getchar();
        printf("Enter The Author Name : ");
        scanf("%[^\n]s", &info_book[i].author_name);
    }
}

void edit_books(Book *info_book) {
    printf("Hello 1");
}

void search_books(Book *info_book) {
    printf("Hello 1");
}

void delete_books(Book *info_book) {
    printf("Hello 1");
}

void dispay_books(Book *info_book) {
    int i = 0;
    while (1) {
        printf("%d", info_book[i].id);
        i++;
    }
}

int main() {
    int choose;
    Book *info_book = (Book *) malloc(1 * sizeof(Book));
    printf("[1] : Add A Book\n");
    printf("[2]: Search About Book\n");
    printf("[3]: Delete A Book\n");
    printf("[4]: Edit Some Information\n");
    printf("[5]: Display The Booksn");
    printf("[6]: Exit\n");
    do {
        printf("\n--------------------------------\n");
        printf("Enter An Operation : ");
        scanf("%d", &choose);
        switch(choose) {
            case 1: {
                add_books(info_book); break;
            }
            case 2: {
                search_books(info_book); break;
            }
            case 3: {
                delete_books(info_book); break;
            }
            case 4: {
                edit_books(info_book); break;
            }
            case 5: {
                dispay_books(info_book); break;
            }
            default: break;
        }
    } while (choose < 6 && choose > 0);
    return 0;
}














