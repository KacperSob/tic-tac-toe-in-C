#include <stdbool.h>

#ifndef TICTACTOE
#define TICTACTOE

void fillTable(char** table, char symbol);
char** createTable();
void displayTable(char** table);
bool checkIfSymbolWon(char** table, char symbol);
char checkWhoWon(char** table);
void destroyTable(char** table);
bool checkIfCanContinue(char** table);

#endif
