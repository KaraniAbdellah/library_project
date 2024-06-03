#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "user.h"
#include "employee.h"

int main() {
    int choose;
    printf("\t\t\t\tHow You Are : \n");
    printf("\t\t\t\t\t[1] : Employee\n");
    printf("\t\t\t\t\t[2] : User\n");
    scanf("%d", &choose); getchar();
    switch(choose) {
        case 1: { Employee(); break; }
        case 2: { printf("\nOpps! Not Implementd Yet\n"); /* User(); */ break; }
        default: printf("\nWrong Number\n");
    }
    return 0;
}

