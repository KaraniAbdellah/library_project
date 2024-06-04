#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "user.h"
#include "employee.h"
// Start Function For User

// Function to display the menu
void DisplayMenu() {
    printf("-- 📋 Menu --\n");
    printf("[1]: Reserve a book\n");
    printf("[2]: View Reserved Books\n");
    printf("[3]: Check book availability\n");
    printf("[4]: Exit\n");
}

// Function Add To File
void add_info_to_file(char *file_name, user *user1) {
    FILE *p_file = fopen(file_name, "a");
    if (p_file == NULL) return;
    else {
        rewind(p_file);
        check_space(&user1->name, &user1->book_name);
        fprintf(p_file, "%s %s %d %d %s\n", user1->book_name, user1->name, user1->duration,
        user1->phone_number, user1->address);
    }
    fclose(p_file);
}

// Function Check If The Presonn Already Exit
int check_preson(Node *head, char name[MAX]) {
    Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}



// Function For Reserve Book
void ReserveBook(user *user1, Node *head) {
    getchar();
    printf("Enter Your Name : ");
    scanf("%[^\n]", user1->name); user1->name[MAX - 1] = '\0'; getchar();
    int check = check_preson(head, user1->name);
    if (!check) {
        printf("Enter You Are Adreesse : ");
        scanf("%[^\n]", user1->address); user1->address[MAX - 1] = '\0'; getchar();
        printf("Enter Your Phone Number : ");
        scanf("%d", &user1->phone_number); getchar();
    }
    if (check) {
        strcpy(user1->address, "XXXX");
        user1->phone_number = 1111111111;
    }
    printf("Enter The Name Of The Book : ");
    scanf("%[^\n]", user1->book_name); user1->book_name[MAX - 1] = '\0';
    printf("Enter The Reservation Period For This Book : ");
    scanf("%d", &user1->duration);
    float price = user1->duration * 0.5;
    printf("The Price is : %.2f$\n",  price);
    printf("❤️  Thank You For Your Confidence ❤️\n");
    add_info_to_file("user.txt", user1);
}

// Function For View Reserved Books
void ViewReservedBooks(Node *head) {
    if (head == NULL) {
        printf("\nYou Didn't Reserve Any Book'\n");
        return;
    } 
    char name[MAX];
    printf("Enter Your Name : "); getchar();
    scanf("%[^\n]", name); name[MAX - 1] = '\0';
    check_space(&name, "test");
    // Start Search For This Client
    Node *temp = head;
    printf("The Book That You Reserve is : ");
    int check = 0;
    while (temp != NULL) {
        if (strcmp(name, temp->name) == 0) {
            printf("%s ", temp->book_name); check++;
        }
        temp = temp->next;
    }
    if (check == 0 && temp == NULL) printf("You Name Does Not Exit\n");
}

// Function For Check Availability
void CheckAvailability() {
    display_all_books_in_file(); // For Get The Available Books
}

// Function That Get The Name Of The Client And Store in Linked List
void get_name(Node **head, char *file_name) {
    FILE *p_file = fopen(file_name, "r");
    if (p_file == NULL) return;
    while (!feof(p_file)) {
        Node *new_node = (Node *) malloc(sizeof(Node));
        if (new_node == NULL) {
            fclose(p_file);
            return;
        }
        if (fscanf(p_file, "%s %s", new_node->book_name, new_node->name) != 2) {
            free(new_node);
            break;
        }
        int c;
        while ((c = fgetc(p_file)) != '\n' && c != EOF);
        new_node->next = *head;
        *head = new_node;
    }
    fclose(p_file);
}


void User() {
    int choice;
    user user1;
    printf("|| Price : 1 Day --> 0.5$ || \n\n");
    do {
        printf("\n=========================\n");
        Node *head = NULL; // Linked List
        get_name(&head, "user.txt");
        DisplayMenu();
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                ReserveBook(&user1, head);
                break;
            }
            case 2: {
                ViewReservedBooks(head);
                break;
            }
            case 3: {
                CheckAvailability();
                break;
            }
            default: {
                printf("Opps! Wrong Number\n");
                break;
                }
        }
        printf("\n=========================\n");
    } while (choice != 4);
}













// End Function For user
