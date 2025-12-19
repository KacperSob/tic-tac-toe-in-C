#include "tictactoe.h"
#include <stdbool.h>
#include "stdio.h"

#ifndef TESTS
#define TESTS

bool _runAllTests(bool shouldDisplayInformation);
bool test1(); // Test if column and row checking works
bool test2(); // Test if angle checking works
bool test3(); // Test if (F.E x/o/x or x/ /x) patterns work
bool test4(); // Test if whole board check works
bool test5(); // Test if empty board check works

#endif // !TESTS
