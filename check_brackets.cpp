#include "check_brackets.h"

int check_brackets::checkList(char *fileName1) // checks the file using a list
{
    std::ifstream file;
    file.open(fileName1);
    if (!file.is_open())
    {
        std::cout << "Error, file is not open" << std::endl;
    }
    std::string buffer;
    int lineNumber = 0;
    stack1.clear();
    DSStack_List<int> stackLineNumbers;
    while (!file.eof())
    {
        lineNumber++;
        getline(file, buffer);
        if (buffer == "" && lineNumber > 100000)
        {
            break;
        }
        std::vector<char> brackets1 = {'[', '(', '{'};
        std::vector<char> brackets2 = {']', ')', '}'};
        for (size_t i = 0; i < buffer.size(); i++)
        {
            if (std::find(brackets1.begin(), brackets1.end(), buffer[i]) != brackets1.end()) // if an open bracket is found
            {
                stack1.push(buffer[i]);
                stackLineNumbers.push(lineNumber);
            }
            else if (std::find(brackets2.begin(), brackets2.end(), buffer[i]) != brackets2.end()) // if a closing bracket is found
            {
                if (stack1.empty()) // if the stack is empty, stray closing bracket
                {
                    std::cout << "stack is empty, stray close bracket, in line number " << lineNumber << std::endl;
                    return 1;
                }
                else if ((stack1.peek() == '[' && ((buffer[i] == '}') || (buffer[i] == ')'))) || (stack1.peek() == '(' && ((buffer[i] == '}') || (buffer[i] == ']'))) || (stack1.peek() == '{' && ((buffer[i] == ')') || (buffer[i] == ']')))) // if it doesnt matches
                {
                    std::cout << fileName1 << ": Bracket mismatch detected for " << buffer[i] << " with " << stack1.peek() << " in line number " << lineNumber << std::endl;
                    return 1;
                }
                else // they match
                {
                    stack1.pop();
                    stackLineNumbers.pop();
                }
            }
        }
    }
    if (stack1.empty())
    {
        std::cout << fileName1 << ": OK" << std::endl;
    }
    else
    {
        std::cout << "stack is not empty at end of file, stray open bracket, in line number " << stackLineNumbers.peek() << std::endl;
    }
    file.close();
    return 0;
}

int check_brackets::checkArray(char *fileName2) // checks the file using an array
{
    std::ifstream file;
    file.open(fileName2);
    if (!file.is_open())
    {
        std::cout << "Error, file is not open" << std::endl;
    }
    std::string buffer;
    int lineNumber = 0;
    stack2.clear();
    DSStack_Array<int> stackLineNumbers;
    std::vector<char> brackets1 = {'[', '(', '{'};
    std::vector<char> brackets2 = {']', ')', '}'};
    while (!file.eof())
    {
        lineNumber++;
        getline(file, buffer);
        if (buffer == "" && lineNumber > 100000)
        {
            break;
        }

        for (size_t i = 0; i < buffer.size(); i++)
        {
            if (std::find(brackets1.begin(), brackets1.end(), buffer[i]) != brackets1.end()) // if an open bracket is found
            {
                stack2.push(buffer[i]);
                stackLineNumbers.push(lineNumber);
            }
            else if (std::find(brackets2.begin(), brackets2.end(), buffer[i]) != brackets2.end()) // if a closing bracket is found
            {
                if (stack2.empty()) // if the stack is empty, stray closing bracket
                {
                    std::cout << "stack is empty, stray close bracket, in line number " << lineNumber << std::endl;
                    return 1;
                }
                else if ((stack2.peek() == '[' && ((buffer[i] == '}') || (buffer[i] == ')'))) || (stack2.peek() == '(' && ((buffer[i] == '}') || (buffer[i] == ']'))) || (stack2.peek() == '{' && ((buffer[i] == ')') || (buffer[i] == ']')))) // if it doesnt matches
                {
                    std::cout << fileName2 << ": Bracket mismatch detected for " << buffer[i] << " with " << stack2.peek() << " in line number " << lineNumber << std::endl;
                    return 1;
                }
                else // they match
                {
                    stack2.pop();
                    stackLineNumbers.pop();
                }
            }
        }
    }
    if (stack2.empty())
    {
        std::cout << fileName2 << ": OK" << std::endl;
    }
    else
    {
        std::cout << "stack is not empty at end of file, stray open bracket, in line number " << stackLineNumbers.peek() << std::endl;
    }
    file.close();
    return 0;
}
