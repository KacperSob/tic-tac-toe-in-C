#include "game.h"
#include <stdio.h>

void menu(){
    short option = 0;
    printf("Choose your game type (0 - exit, 1 - vs player)\n");
    scanf("%hd", &option);
    switch (option) {
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            main_vs_player();
            break;
        default:
            printf("Choose a correct option\n");
            menu();
            break;
    }
}

void main_vs_player(){
    char** table = createTable();
    int row, column;
    char winner = '-';
    short currentPlayer = 1;
    while (checkIfCanContinue(table)) {
        printf("Choose your row and column (1-3) \n");
        if(currentPlayer == 1){
            printf("Now player X \n");
            scanf("%d %d", &row, &column);
            table[row-1][column-1] = 'x';
            currentPlayer = 2;
        } else {
            printf("Now player O \n");
            scanf("%d %d", &row, &column);
            table[row-1][column-1] = 'o';
            currentPlayer = 1;
        }
        winner = checkWhoWon(table);
        if(winner != '-'){
            displayTable(table);
            printf("%c HAS WON! \n", winner);
            break;
        }
        displayTable(table);
    }
    if(winner == '-'){
        displayTable(table);
        printf("That's a DRAW!\n");
    }
    menu();
}
