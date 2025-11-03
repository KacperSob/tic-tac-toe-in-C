#include "tictactoe.h"
#include "stdlib.h"
#include "stdio.h"
#include <stdbool.h>

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

// Checks if a specific symbol has won
bool checkIfSymbolWon(char** table, char symbol){
    bool output = true;
    // Check columns
    for(int i = 0; i < 3; i++){
        output = true;
        for(int j = 0; j < 3; j++){
            if(table[j][i] != symbol){
                output = false;
            }
        }
        if(output){
            return true;
        }
    }
    
    output = true;
    // Check rows
    for(int i = 0; i < 3; i++){
        output = true;
        for(int j = 0; j < 3; j++){
            if(table[i][j] != symbol){
                output = false;
            }
        }    
        if(output){
            return true;
        }
    } 
    output = true;
    // Check angle 
    for(int i = 0; i < 3; i++){
        if(table[i][i] != symbol){
            output = false;
        }
    }
    if(output){
        return true;
    }
    output = true;
    for(int i = 0; i < 3; i++){
        if(table[2-i][i] != symbol){
            output = false;
        }
    }
    return output;
} 

char checkWhoWon(char** table){
    if(checkIfSymbolWon(table, 'x')){
        return 'x';
    }
    if(checkIfSymbolWon(table, 'o')){
        return 'o';
    }
    return '-';
}

void destroyTable(char** table){
    for(int i = 0; i < 3; i++){
        free(table[i]);
    }
    free(table);
}

