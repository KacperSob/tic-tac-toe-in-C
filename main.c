#include "stdio.h"
#include "lib/tictactoe.h"

int main (int argc, char *argv[]) {
    char** table = createTable();
    table[0][0] = 'x';
    table[1][1] = 'o';
    table[2][2] = 'x';
    displayTable(table);
    printf("Wygral %c\n", checkWhoWon(table));
    destroyTable(table);
    return 0;
}
