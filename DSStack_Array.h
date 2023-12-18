#ifndef DSStack_Array_H
#define DSStack_Array_H

template <typename Object>
class DSStack_Array
{
private:
    int len;
    int capacity;
    Object *array;

public:
    DSStack_Array() // default constructor
    {
        len = 0;
        capacity = 10;
        array = new Object[capacity];
    }

    ~DSStack_Array() // destructor
    {
        delete[] array;
    }

    DSStack_Array &operator=(const DSStack_Array &rhs) // assignment operator
    {
        delete[] array;
        len = rhs.len;
        capacity = rhs.capacity;
        array = new Object[capacity];
        for (int i = 0; i < len; i++)
        {
            array[i] = rhs.array[i];
        }
        return *this;
    }

    DSStack_Array(const DSStack_Array &rhs) // copy constructor
    {
        len = rhs.len;
        capacity = rhs.capacity;
        array = new Object[capacity];
        for (int i = 0; i < len; i++)
        {
            array[i] = rhs.array[i];
        }
    }

    void push(Object x) // adds an element on to the top of the stack
    {
        array[len] = x;
        len++;
        if (len == capacity)
        {
            resize();
        }
    }

    Object peek() // returns the element that is on top of the stack
    {
        if (len == 0) 
        {
            std::cerr << "stack is empty" << std::endl;
        }
        return array[len - 1];
    }

    void pop() // removes the element that is on top of the stack
    {
        if (len == 0) 
        {
            std::cerr << "stack is empty" << std::endl;
        }
        len--;
    }

    bool empty() // checks to see if the stack is empty
    {
        if (len == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void resize() // resizes the array
    {
        capacity *= 2;
        Object *temp = new Object[capacity];
        for (int i = 0; i < len; i++)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
    }

    void clear() // clears the array
    {
        delete[] array;
        len = 0;
        capacity = 10;
        array = new Object[capacity];
    }
};
#endif
