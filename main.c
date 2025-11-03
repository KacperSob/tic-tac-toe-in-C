#include "stdio.h"
#include "lib/tictactoe.h"
#include "lib/tests.h"

int main (int argc, char *argv[]) {
    bool output = _runAllTests(true);
    printf("Overall test ouput: %d\n", output);
    return 0;
}
