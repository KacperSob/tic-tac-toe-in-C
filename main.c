#include "stdio.h"
#include "lib/tictactoe.h"

int main (int argc, char *argv[]) {
    char** table = createTable();
    displayTable(table);
    destroyTable(table);
    return 0;
}
