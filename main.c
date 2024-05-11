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
    struct Info *info_book;
    struct Book *next;
} Book;

typedef struct Info {
    int id;
    char book_name[50];
    char author_name[50];
} Info;

// Start Add Function
Book *create_book(Book *book) {
    Book *new_book = (Book *) malloc(sizeof(Book));
    printf("Enter Name Of The Book : "); getchar();
    scanf("%[^\n]", &new_book->info_book->book_name);
    printf("Enter The Id Of The Book : ");
    scanf("%d", &new_book->info_book->id); getchar();
    printf("Enter The Author Name : ");
    scanf("%[^\n]", &new_book->info_book->author_name);
    book->next = new_book;
    return new_book;
}

Book *add_books(Book *book, int *nbr_of_book) {
    int book_nbr;
    printf("Enter Number Of Books : ");
    scanf("%d", &book_nbr);
    Book *new_book = (Book *) malloc(sizeof(Book));
    for (int i = 0; i < book_nbr; i++) {
        printf("\n-- Book %d\n", i + 1);
        book = create_book(book);
    }
    *nbr_of_book += book_nbr;
    return book;
}
// End Add Function

/*
// Start Edit Function
void edit_books(Book *info_book, int nbr_of_book) {
    // Test Is This Book Exit
    int pos = search_bookName(info_book, nbr_of_book);
    if (pos != -1) {
        char new_book_name[50];
        printf("\nEnter New Book Name : ");
        // gets(new_book_name);
        scanf("%[^\n]s", new_book_name); new_book_name[49] = '\0';
        strcpy(info_book[pos].book_name, new_book_name);
    }
    // Test Is This Author Exit
    pos = search_authorName(info_book, nbr_of_book);
    if (pos != -1) {
        char new_author_name[50];
        printf("\nEnter New Author Name : ");
        // gets(new_author_name);
        scanf("%[^\n]s", new_author_name); new_author_name[49] = '\0';
        strcpy(info_book[pos].author_name ,new_author_name);
    }
    // Test Is This Author Exit
    pos = search_id(info_book, nbr_of_book);
    if (pos != -1) {
        char new_id;
        printf("\nEnter New Id : ");
        scanf("%d", &new_id);
        info_book[pos].id = new_id;
    }
}
// End Edit Function


// Start Search Function
int search_bookName(Book *info_book, int nbr_of_book) {
    char book_name[50]; getchar();
    printf("Enter The Name Of Book : ");
    gets(book_name);
    // Start Searching About The Books
    for (int i = 0; i < nbr_of_book; i++) {
        if (strcmp(book_name, info_book[i].book_name) == 0) {
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", info_book[i].id, info_book[i].book_name, info_book[i].author_name);
            return i;
        }
    }
    printf("\t\t\t\t\tWe Can Not Found %s At List\n", book_name);
    return -1;
}

int search_authorName(Book *info_book, int nbr_of_book) {
    char author_name[50]; getchar();
    printf("Enter The Author Of Book : ");
    gets(author_name);
    // scanf("%[^\n]s", author_name); author_name[49] = '\0';
    // Start Searching About The Books
    for (int i = 0; i < nbr_of_book; i++) {
        if (strcmp(author_name, info_book[i].author_name) == 0) {
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", info_book[i].id, info_book[i].book_name, info_book[i].author_name);
            return i;
        }
    }
    printf("\t\t\t\t\tWe Do Not Fount %s At List\n", author_name[50]);
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
    printf("\t\t\t\t\tWe Do Not Fount %d At List\n", id);
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

*/
// Start Display Function
void dispay_books(Book *book) {
    if (book == NULL) printf("\nThe List is Empty\n");
    else {
        Book *temp = book;
        int i = 0;
        while (temp != NULL) {
            printf("\nBOOK %d : \n", i + 1);
            printf("%d %s %s", temp->info_book->id, temp->info_book->author_name, temp->info_book->book_name);
            // printf("%d %s %s", info_book[i].id, info_book[i].author_name, info_book[i].book_name);
            temp = temp->next;
            i++;
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
    int choose, nbr_of_book = 0;
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
                book = add_books(book, &nbr_of_book); break;
            }
            case 2: {
                //search_books(info_book, nbr_of_book); break;
            }
            case 3: {
                //delete_books(info_book, nbr_of_book); break;
            }
            case 4: {
                //edit_books(info_book, nbr_of_book); break;
            }
            case 5: {
                //dispay_books(info_book, nbr_of_book); break;
            }
            case 6: {
                //trach(info_book, nbr_of_book);
                break;
            }
            default: break;
        }
    } while (choose < 6 && choose > 0);
    return 0;
}














