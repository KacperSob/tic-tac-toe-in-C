#include "tests.h"

bool _runAllTests(bool shouldDisplayInformation){
    bool output = true;
    bool test;
    if(shouldDisplayInformation){
        test = test1();
        if(!test){
            output = false;
        }
        printf("test1 %d\n", test);
        test = test2();
        if(!test){
            output = false;
        }
        printf("test2 %d\n", test);
        test = test3();
        if(!test){
            output = false;
        }
        printf("test3 %d\n", test);


        return output;
    }
    if(!test1()) {output = false;}
    if(!test2()) {output = false;}
    if(!test3()) {output = false;}

    return output;
}

bool test1(){
    char** table = createTable();
    bool output = true;
    table[0][0] = 'x';
    table[0][1] = 'x';
    table[0][2] = 'x';
    if(checkWhoWon(table) != 'x'){
        displayTable(table);
        output = false;
    }
    fillTable(table, ' ');
    table[0][1] = 'o';
    table[1][1] = 'o';
    table[2][1] = 'o';
    if(checkWhoWon(table) != 'o'){
        output = false;
    }
    destroyTable(table);
    return output;
}

bool test2(){
    char** table = createTable();
    bool output = true;
    table[0][0] = 'x';
    table[1][1] = 'x';
    table[2][2] = 'x';
    if(checkWhoWon(table) != 'x'){
        output = false;
    }
    fillTable(table, ' ');
    table[2][0] = 'o';
    table[1][1] = 'o';
    table[0][2] = 'o';
    if(checkWhoWon(table) != 'o'){
        output = false;
    }
    destroyTable(table);
    return output;
}

bool test3(){
    char** table = createTable();
    bool output = true;
    table[0][0] = 'x';
    table[1][1] = 'o';
    table[2][2] = 'x';
    if(checkWhoWon(table) != '-'){
        output = false;
    }
    fillTable(table, ' ');
    table[0][0] = 'x';
    table[0][1] = ' ';
    table[0][2] = 'x';
    if(checkWhoWon(table) != '-'){
        output = false;
    }
    fillTable(table, ' ');
    table[0][0] = ' ';
    table[1][1] = ' ';
    table[2][2] = ' ';
    if(checkWhoWon(table) != '-'){
        output = false;
    }
    fillTable(table, ' ');
    table[0][0] = 'x';
    table[1][0] = 'o';
    table[2][0] = ' ';
    if(checkWhoWon(table) != '-'){
        output = false;
    }
    fillTable(table, ' ');

    destroyTable(table);
    return output;
}
