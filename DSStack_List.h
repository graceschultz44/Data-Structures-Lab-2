#ifndef DSStack_List_H
#define DSStack_List_H
#include "DSList.h"

template <typename Object>
class DSStack_List
{
private:
    DSList<Object> stack;

public:
    void push(Object x) // pushes an element onto the stack
    {
        stack.insertEnd(x);
    }
    Object peek() // returns the element on top of the stack
    {
        int size = stack.getSize();
        return stack[size - 1];
    }
    void pop() // removes the element on top of the stack
    {
        stack.removeLast();
    }
    bool empty() // returns whether the stack is empty or not
    {
        return stack.empty();
    }
    void clear() // clears the stack
    {
        stack.clear();
    }
};
#endif
