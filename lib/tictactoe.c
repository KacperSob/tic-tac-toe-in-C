#include "tictactoe.h"
#include "stdlib.h"

char** createTable(){
    char **table = malloc(3*sizeof(int*));
    for(int i = 0; i < 3; i++){
        table[i] = malloc(3*sizeof(int));
    }
    return table;
}

