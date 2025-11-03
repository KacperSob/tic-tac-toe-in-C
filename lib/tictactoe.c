#include "tictactoe.h"
#include "stdlib.h"
#include "stdio.h"

void fillTable(char** table, char symbol){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            table[i][j] = symbol;
        }
    }
}

char** createTable(){
    char **table = (char**)malloc(3*sizeof(char*));
    if (!table) return NULL;
    for(int i = 0; i < 3; i++){
        table[i] = (char*)malloc(3*sizeof(char));
        if (!table[i]) {
            for (int j = 0; j < i; j++) free(table[j]);
            free(table);
            return NULL;
        }
    }
    fillTable(table, ' ');
    return table;
}

void displayTable(char** table){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }    
}

void destroyTable(char** table){
    for(int i = 0; i < 3; i++){
        free(table[i]);
    }
    free(table);
}

