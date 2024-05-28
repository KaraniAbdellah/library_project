#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "myLib.h"
#define MAX_BOOK_NAME_LENGTH 50
#define MAX_AUTHOR_NAME_LENGTH 50

/* ******* @copyright 2024 May 19 23:00 || Made With Love By ABDELLAH KARANI ****** */

// In This Project Her Is The Importante Function
/*
    - Add A Book --> Add A Lot Of Information
    - Search About A Book
    - Delete A Book
    - Delete All Books
    - Edit Some Information About The Book [id, name, author]
    - Show Books
    - Trach Books

		------- >> Must The Data Add To Two Filies book.txt and trach.txt
		
		////////////// As We Know We Stell Need More Fonctionallity Like : 
			--> Check If We have A Duplicates Book_name or Author_name or Ids.
			--> Every Thing Shound Be In Filies [Edit, Search, Add, Delete, Display].


		------- >> Next Project About Bank System We Will Try To Do it.
*/

// Strcture
typedef struct Book {
    int id;
    char book_name[MAX_BOOK_NAME_LENGTH];
    char author_name[MAX_AUTHOR_NAME_LENGTH];
    struct Book *next;
} Book;


typedef struct Trach {
    int id;
    char book_name[MAX_BOOK_NAME_LENGTH];
    char author_name[MAX_AUTHOR_NAME_LENGTH];
    struct Trach *next;
	struct Trach *prev;
} Trach;


typedef struct Pin {
    int id;
    char book_name[MAX_BOOK_NAME_LENGTH];
    char author_name[MAX_AUTHOR_NAME_LENGTH];
    struct Pin *next;
	struct Pin *prev;
} Pin;


void add_to_file(Book *new_book, char fileName[]) {
	FILE *p_file = fopen(fileName, "a");
	rewind(p_file);
	if (p_file == NULL) { return; printf("\nCan Not Open This File\n"); }
	else {
		printf("Opening The File Succfully :-- %s --\n ", new_book->book_name);
		fprintf(p_file, "%d %s %s\n", new_book->id, new_book->book_name, new_book->author_name);
	}
}

// Start Add Function
void create_book(Book ***book) {
    char new_id[50];
    Book *new_book = (Book *)malloc(sizeof(Book));
    getchar();
  	printf("Enter Name Of The Book : ");
  	scanf("%49[^\n]", new_book->book_name); new_book->book_name[49] = '\0';
  	// Check If This BookName Already Exit By Open The File
  	getchar();
    printf("Enter The Id Of The Book : ");
    scanf("%49[^\n]", new_id); new_id[49] = '\0';
    // Check If This Id Already Exit By Open The File
    getchar();
    new_book->id = atoi(new_id);
    printf("Enter The Author Name : ");
    scanf("%49[^\n]", new_book->author_name); new_book->author_name[49] = '\0';
    // Check If This Author Name Already Exit By Open The File
    new_book->next = NULL;
    new_book->next = **book;
    **book = new_book;
	// Add Book In File "book.txt"
    add_to_file(new_book, "book.txt");
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
    printf("Enter The Name Of The Book : ");  getchar(); 
    scanf("%[^\n]", book_name); book_name[49] = '\0';
    // Find The Book
    while (1) {
        if (strcmp(temp->book_name, book_name) == 0) {
            char new_book_name[50];
            printf("Enter The New Name : "); getchar();
            scanf("%[^\n]", new_book_name); new_book_name[49] = '\0';
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
    scanf("%[^\n]", author_name); author_name[49] = '\0';
    // Find The Book
    while (1) {
        if (strcmp(temp->author_name, author_name) == 0) {
            char new_author_name[50];
            printf("Enter The New Name : "); getchar();
            scanf("%[^\n]", new_author_name); new_author_name[49] = '\0';
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
            scanf("%d", &new_id);
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
        default: {
        	printf("\nWorrong Number\n"); break;
        }
    }
}
// End Edit Function


// Start Search Function
int search_bookName(Book *book) {
    int index = 0;
    char book_name[50]; getchar();
    printf("Enter The Name Of Book : ");
    scanf("%[^\n]", book_name); book_name[49] = '\0';
    // Start Searching About The Books
    Book *temp = book;
    while (temp != NULL) {
        if (strcmp(book_name, temp->book_name) == 0) {
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", temp->id, temp->book_name, temp->author_name);
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
    scanf("%[^\n]", author_name); author_name[49] = '\0';
    // scanf("%[^\n]s", author_name); author_name[49] = '\0';
    Book *temp = book;
    while (temp != NULL) {
        if (strcmp(author_name, temp->author_name) == 0) {
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", temp->id, temp->book_name, temp->author_name);
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
            printf("\t\t\t\t\tWe Found The Book : %d %s %s", temp->id, temp->book_name, temp->author_name);
            return index;
        }
        index++; temp = temp->next;
    }
    printf("\t\t\t\t\tWe Can Not Found %d At List\n", id);
    return -1;
}

int search_books(Book *book) {
    int choose_search;
    printf("\t\t\t\t\t[1]: Search Using Book Name\n");
    printf("\t\t\t\t\t[2]: Search Using Author Name\n");
    printf("\t\t\t\t\t[3]: Search Using Id Name\n");
    printf("Choose Method For Searching : ");
    scanf("%d", &choose_search);
    choose_search = (int) choose_search;
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
        default: {
        	printf("\nWorrong Number\n"); break;
        }
    }
}
// End Search Function


// Start Trach Function
void add_to_trach(Book *book_deleted, Trach ****trach_books, Trach ****tail) {
	// printf("%d %s %s\n", book_deleted->id, book_deleted->book_name, book_deleted->author_name);
	Trach *new_node = (Trach *) malloc(sizeof(Trach));
	new_node->next = new_node->prev = NULL;
	new_node->id = book_deleted->id;
	strcpy(new_node->book_name, book_deleted->book_name);
	strcpy(new_node->author_name, book_deleted->author_name);
	if (***trach_books == NULL) {
		***trach_books = ***tail = new_node; 
	} else {
		new_node->prev =  ***tail;
		(***tail)->next = new_node;
		***tail = new_node;
	}
}
// End Trach Function


// Start Delete Function
void delete_bookName(Book ***book, Trach ***trach_books, Trach ***tail) {
    if (**book != NULL) {
		Book *temp = **book;
		char book_name[50];
		printf("Enter The Name Of Book : "); getchar();
		scanf("%[^\n]", book_name); book_name[49] = '\0';
		if (strcmp(book_name, temp->book_name) == 0) {
			if ((**book)->next == NULL) **book = NULL;
			(**book)= temp->next;
			// Add To Trach
			add_to_trach(temp, &trach_books, &tail);
			// Add To File
			add_to_file(temp, "trach.txt");
			free(temp);
			printf("\nDeleted The Book Succefully : %s\n", book_name); 
		} else {
			while (temp->next != NULL) {
				if (strcmp(book_name, temp->next->book_name) == 0) {
					Book *p = temp->next;
					// Add To Trach
					add_to_trach(p, &trach_books, &tail);
					// Add To File
					add_to_file(p, "trach.txt");
					temp->next = p->next;
					free(p); printf("\nDeleted The Book Succefully : %s\n", book_name);
					break;
				}
				temp = temp->next;
			}
            if (temp->next == NULL) {
                printf("\nCannot Find This Book\n");
            }
		}   
    } else printf("\nNo Book Exit\n");
}


void delete_authorName(Book ***book, Trach ***trach_books, Trach ***tail) {
    if (**book != NULL) {
		Book *temp = **book;
		char author_name[50];
		printf("Enter The Author Of Book : "); getchar();
		scanf("%[^\n]", author_name); author_name[49] = '\0';
		if (strcmp(author_name, temp->author_name) == 0) {
			if ((**book)->next == NULL) **book = NULL;
			(**book)= temp->next;
			// Add To Trach
			add_to_trach(temp, &trach_books, &tail);
			// Add To File
			add_to_file(temp, "trach.txt");
			free(temp);
			printf("\nDeleted The Book Succefully : %s\n", author_name); 
		} else {
			while (temp->next != NULL) {
				if (strcmp(author_name, temp->next->author_name) == 0) {
					Book *p = temp->next;
					// Add To Trach
					add_to_trach(p, &trach_books, &tail);
					// Add To File
					add_to_file(p, "trach.txt");
					temp->next = p->next;
					free(p); printf("\nDeleted The Book Succefully : %s\n", author_name);
					break;
				}
				temp = temp->next;
			}
            if (temp->next == NULL) {
                printf("\nCannot Find This Book\n");
            }
		}   
    } else printf("\nNo Book Exit\n");
}


void delete_id(Book ***book, Trach ***trach_books, Trach ***tail) {
    if (**book != NULL) {
		Book *temp = **book;
		int id;
		printf("Enter The Id Of Book : ");
		scanf("%d", &id);
		if (temp->id == id) {
			if ((**book)->next == NULL) **book = NULL;
			(**book)= temp->next;
			// Add To Trach
			add_to_trach(temp, &trach_books, &tail);
			// Add To File
			add_to_file(temp, "trach.txt");
			free(temp);
			printf("\nDeleted The Book Succefully : %d\n", id); 
		} else {
			while (temp->next != NULL) {
				if (id == temp->next->id) {
					Book *p = temp->next;
					// Add To Trach
					add_to_trach(p, &trach_books, &tail);
					// Add To File
					add_to_file(p, "trach.txt");
					temp->next = p->next;
					free(p); printf("\nDeleted The Book Succefully : %d\n", id);
					break;
				}
				temp = temp->next;
			}
            if (temp->next == NULL) {
                printf("\nCannot Find This Book\n");
            }
		}   
    } else printf("\nNo Book Exit\n");
}

void delete_books(Book **book, Trach **trach_books, Trach **tail) {
    // Choose Deleting
    int choose_delete;
    printf("\t\t\t\t\t[1]: Deleting Using Book Name\n");
    printf("\t\t\t\t\t[2]: Deleting Using Author Name\n");
    printf("\t\t\t\t\t[3]: Deleting Using Id Name\n");
    printf("Choose Method For Deleting : ");
    scanf("%d", &choose_delete);
    choose_delete = (int) choose_delete;
    switch(choose_delete) {
        case 1: {
            delete_bookName(&book, &trach_books, &tail); break;
        }
        case 2: {
            delete_authorName(&book, &trach_books, &tail); break;
        }
        case 3: {
            delete_id(&book, &trach_books, &tail); break;
        }
        default: {
        	printf("\nWorrong Number\n"); break;
        }
    }
}
// End Delete Function


// Start Display Function
void dispay_books(Book *book) {
    if (book == NULL) printf("\nNo Book Exit\n");
    else {
        Book *temp = book;
		printf("\n--Id-- \t --Book_Name-- \t --Author_Name--\n\n");
        while (temp != NULL) {
            printf("%d \t %s \t %s\n", temp->id, temp->book_name, temp->author_name);
            temp = temp->next;
        }
    }
}
// End Display Function



// Start display all book from file
void display_all_books_in_file() {
	FILE *p_file = fopen("book.txt", "r");
	if (p_file == NULL) return;
	else {
		char book[50], author[50];
		int id;
		printf("\n--Id-- \t --Book_Name-- \t --Author_Name--\n\n");
		while (!feof(p_file)) {
			fscanf(p_file, "%d %s %s", &id, book, author);
			printf("%d \t %s \t %s\n", id, book, author);
		}
	}
}
// End display all book from file


// Start Trach Function For Display
void display_trach(Trach *trach_books) {
	if(trach_books == NULL) printf("\nThe Trach Empty\n");
	else {
		Trach *temp = trach_books;
		printf("\n--Id-- \t --Book_Name-- \t --Author_Name--\n\n");
        while (temp != NULL) {
            printf("%d \t %s \t %s\n", temp->id, temp->book_name, temp->author_name);
            temp = temp->next;
        }
	}
}
// End Trach Function

// Start Display All Books In Trach
void display_all_books_in_trach() {
	FILE *p_file = fopen("trach.txt", "r");
	if (p_file == NULL) return;
	else {
		char book[50], author[50];
		int id;
		printf("\n--Id-- \t --Book_Name-- \t --Author_Name--\n\n");
		while (!feof(p_file)) {
			fscanf(p_file, "%d %s %s", &id, book, author);
			printf("%d \t %s \t %s\n", id, book, author);
		}
	}
}
// End Display All Books In Trach

// Start Delete From Trach
void delete_trach_bookName(Trach ***trach_books, Trach ***tail) {
	printf("\nNot Implemented Yet : \n");
}
void delete_trach_authorName(Trach ***trach_books, Trach ***tail) {
	printf("\nNot Implemented Yet : \n");
}
void delete_trach_id(Trach ***trach_books, Trach ***tail) {
	printf("\nNot Implemented Yet : \n");
}
void delete_from_trach(Trach **trach_books, Trach **tail) {
    // Choose Deleting
    int choose_delete;
    printf("\t\t\t\t\t[1]: Deleting Using Book Name\n");
    printf("\t\t\t\t\t[2]: Deleting Using Author Name\n");
    printf("\t\t\t\t\t[3]: Deleting Using Id Name\n");
    printf("Choose Method For Deleting : ");
    scanf("%d", &choose_delete);
    choose_delete = (int) choose_delete;
    switch(choose_delete) {
        case 1: {
            delete_trach_bookName(&trach_books, &tail); break;
        }
        case 2: {
            delete_trach_authorName(&trach_books, &tail); break;
        }
        case 3: {
            delete_trach_id(&trach_books, &tail); break;
        }
        default: {
        	printf("\nWorrong Number\n"); break;
        }
    }	
}
// End Deleted From Trach

// Start Pin A Book
void pin_book() {
	
}
// End Pin A Book

// Start Display Pins Books
void display_pin_books() {

}
// End Display Al Pins Books

// Start Display All Pins Books
void display_all_pin_books() {
	
}
// End Display All Pins Books 



int main() {
    char choose_nbr[4]; choose_nbr[3] = '\0';
    Book *book = NULL;
    Trach *trach_books = NULL; Trach *tail = NULL;
	Pin *pin_books = NULL; Pin *summit = NULL;
	// Loading Feature	
	// loading();
    printf("[1]: Add A Book\n");
    printf("[2]: Search About Book\n");
    printf("[3]: Delete A Book\n");
    printf("[4]: Edit Some Information\n");
    printf("[5]: Display The Books\n");
    printf("[6]: Display All Books In File\n");
    printf("[7]: Display The Trach\n");
    printf("[8]: Display All Books In Trach File\n");
	printf("[9]: Delete From Trach\n");
    printf("[10]: Pin A Book\n"); // Using Just The Id
	printf("[11]: Display The Pin Books\n");
	printf("[12]: Display All Pin Books In File\n");
	printf("[13]: Exit\n");
	// Free Trach And Free File And Free Linked List And Free Pin And Free Filies
    printf("Note : If You Are Enter A Number In Id Will Be Considered Like 0:\n");
    int choose;
    do {
        printf("\n--------------------------------\n");
        printf("Enter An Operation : ");
        scanf("%[^\n]", choose_nbr);
        choose = atoi(choose_nbr);
        switch(choose) {
            case 1: {
                add_books(&book); break;
            }
            case 2: {
                search_books(book); break;
            }
            case 3: {
                delete_books(&book, &trach_books, &tail); break;
            }
            case 4: {
                edit_books(book); break;
            }
            case 5: {
                dispay_books(book); break;
            }
            case 6: {
                display_all_books_in_file(); break;
                break;
            }
            case 7: {
                display_trach(trach_books); break;
                break;
            }
            case 8: {
                display_all_books_in_trach(); break;
            }
            case 9: {
                delete_from_trach(&trach_books, &tail); break;
            }
            case 10: {
                pin_book(); break;
            }
            case 11: {
                display_pin_books(book); break;
            }
            case 12: {
                display_all_pin_books(book); break;
            }
            default: break;
        }
        getchar();
    } while (choose < 12 && choose > 0);
    return 0;
}













