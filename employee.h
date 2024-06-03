#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#define MAX 50

    // Linked List
    typedef struct Book {
        int id;
        char book_name[MAX];
        char author_name[MAX];
        struct Book *next;
    } Book;

    // Stack
    typedef struct Trach {
        int id;
        char book_name[MAX];
        char author_name[MAX];
        struct Trach *next;
	    struct Trach *prev;
    } Trach;

    // Queue
    typedef struct Pin {
        int id;
        char book_name[MAX];
        char author_name[MAX];
        struct Pin *next;
	    struct Pin *prev;
    } Pin;

    // Start Prototype Of The Employee Function
    void Employee();
    void add_to_file(void *new_item, char fileName[]);
    void create_book(Book ***book);
    void add_books(Book **book);
    void edit_bookName(Book *book);
    void edit_authorName(Book *book);
    void edit_id(Book *book);
    void edit_books(Book *book);
    int search_bookName(Book *book);
    int search_authorName(Book *book);
    int search_id(Book *book);
    int search_books(Book *book);
    void add_to_trach(Book *book_deleted, Trach ****trach_books, Trach ****tail);
    void delete_bookName(Book ***book, Trach ***trach_books, Trach ***tail);
    void delete_authorName(Book ***book, Trach ***trach_books, Trach ***tail);
    void delete_id(Book ***book, Trach ***trach_books, Trach ***tail);
    void delete_books(Book **book, Trach **trach_books, Trach **tail);
    void dispay_books(Book *book);
    void display_all_books_in_file();
    void display_trach(Trach *trach_books);
    void display_all_books_in_trach();
    void delete_trach_bookName(Trach ***trach_books, Trach ***tail);
    void delete_trach_authorName(Trach ***trach_books, Trach ***tail);
    void delete_trach_id(Trach ***trach_books, Trach ***tail);
    void delete_from_trach(Trach **trach_books, Trach **tail);
    void pin_book(Pin **pin_books, Pin **summit);
    void display_pin_books(Pin *pin_books);
    void display_all_pin_books();
    // End Prototype Of The Employee Function
#endif





