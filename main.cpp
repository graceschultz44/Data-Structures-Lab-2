#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdio>
#include "check_brackets.h"

int main(int argc, char **argv)
{
    check_brackets check;
    for (int i = 1; i < argc; ++i)
    {
        check.checkList(argv[i]);
        check.checkArray(argv[i]);
    }
    return 0;
}
