#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "user.h"
#include "employee.h"

int main() {
    int choose;
    printf("\t\t\t\t\t👋✨ Welcome! ✨👋\n");
    printf("\t\t\t\t\t================\n");
    printf("\t\t\t\t\t👦 [1] Employee\n");
    printf("\t\t\t\t\t👦 [2] User\n");
    printf("\t\t\t\t\t================\n");
    printf("\t\t\t\t\tYour Chooce : ");
    scanf("%d", &choose); getchar(); printf("\n");
    switch(choose) {
        case 1: { loading(); Employee(); break; }
        case 2: { loading(); User(); break; }
        default: printf("\nWrong Number\n");
    }
    return 0;
}

