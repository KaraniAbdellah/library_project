#ifndef USER_H
#define USER_H

#define MAX 50

typedef struct user {
    char name[MAX];
    char address[MAX];
    int phone_number;
    int duration;
    char book_name[MAX];
} user;

typedef struct Node {
    char name[MAX];
    char book_name[MAX];
    struct Node *next;
} Node;

// Start Prototype Of The User Functions 
    void User();
    void DisplayMenu();
    void ReserveBook();
    void ViewReservedBooks();
    void CheckAvailability();
    int generateRandomNumber();


// End Prototype Of The User Functions 
#endif
