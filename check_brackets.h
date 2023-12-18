#ifndef CHECK_BRACKETS_H
#define CHECK_BRACKETS_H
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "DSList.h"
#include "DSStack_List.h"
#include "DSStack_Array.h"

class check_brackets
{
private:
    DSStack_List<char> stack1;
    DSStack_Array<char> stack2;

public:
    int checkList(char *);
    int checkArray(char *);
};
#endif
