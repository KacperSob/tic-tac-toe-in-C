#include "game.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>

void menu(){
    short option = 0;
    printf("Choose your game type (0 - exit, 1 - vs player, 2 - vs machine)\n");
    scanf("%hd", &option);
    switch (option) {
        case 0:
            printf("Exiting...\n");
            break;
        case 1:
            main_vs_player();
            break;
        case 2:
            player_vs_machine();
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
    destroyTable(table);
    menu();
}

void player_vs_machine(){
    srand(time(NULL));
    char** table = createTable();
    int row, column;
    char winner = '-';
    short currentPlayer = 1;

    printf("Choose your symbol 1 - X, 2 - O\n");
    scanf("%hd", &currentPlayer);

    while (checkIfCanContinue(table)) {
        printf("Choose your row and column (1-3) \n");
        if(currentPlayer == 1){
            scanf("%d %d", &row, &column);
            table[row-1][column-1] = 'x';
        } else {
            scanf("%d %d", &row, &column);
            table[row-1][column-1] = 'o';
        }

        do { 
            row = rand()%3;
            column = rand()%3;
        }while (table[row][column] != ' ');

        if(currentPlayer == 1){
            table[row][column] = 'o';
        } else {
            table[row][column] = 'x';
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
    destroyTable(table);
    menu();
}
