#ifndef DSList_H
#define DSList_H

template <typename Object>
class DSList
{
private:
    struct Node
    {
        Object data;
        Node *next;
        Node *previous;
        Node(const Object &d = Object{}, Node *n = nullptr, Node *p = nullptr)
            : data{d}, next{n}, previous{p} {}
    };
    Node *head;
    Node *tail;
    int size;

public:
    DSList() // default constructor
        : head{nullptr}, tail{nullptr}, size{0}
    {
    }

    DSList(const Object &x) // copy constructor
    {
        if (x.size == 0)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = new Node(x.head->data);
            Node *temp1 = x.head->next;
            tail = head;
            head->previous = tail;
            tail->previous = head;
            head->next = tail;
            tail->next = head;
            while (temp1 != nullptr)
            {
                Node *newNode = new Node(temp1->data);
                tail->next = newNode;
                newNode->previous = tail;
                newNode->next = head;
                head->previous = newNode;

                tail = tail->next;
                temp1 = temp1->next;
            }
            size = x.size;
        }
    }

    ~DSList() // destructor
    {
        clear();
    }

    Object &operator=(const Object &x) // assignment operator
    {
        clear();
        if (x.size == 0)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = new Node(x.head->data);
            Node *temp1 = x.head->next;
            tail = head;
            head->previous = tail;
            tail->previous = head;
            head->next = tail;
            tail->next = head;
            while (temp1 != nullptr)
            {
                Node *newNode = new Node(temp1->data);
                tail->next = newNode;
                newNode->previous = tail;
                newNode->next = head;
                head->previous = newNode;

                tail = tail->next;
                temp1 = temp1->next;
            }
            size = x.size;
        }
        return *this;
    }

    Object &operator[](const int &x) // brackets operator
    {
        if (x < 0 || x >= size)
        {
            std::cerr << "Index is out of bounds: " << x << ", " << size << std::endl;
        }
        if (x == size - 1)
        {
            return tail->data;
        }
        Node *temp = head;
        for (int i = 0; i < x && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    int getSize() const // size
    {
        return size;
    }

    void clear() // clear the whole list
    {
        while (!empty())
        {
            removeFirst();
        }
        size = 0;
    }

    int find(const Object &x) const // find an element with a specific value (and return the position. First element in list is pos 0). Not found returns -1.
    {
        int i = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == x)
            {
                return i;
            }
            temp = temp->next;
            i++;
        }
        return -1;
    }

    void insertBeginning(const Object &x) // insert at the beginning of the list (push_front).
    {
        if (head == nullptr)
        {
            head = new Node(x);
            tail = head;
            head->previous = tail;
            tail->previous = head;
            head->next = tail;
            tail->next = head;
        }
        else
        {
            Node *newNode = new Node(x);
            newNode->previous = tail;
            newNode->next = head;
            tail->next = newNode;
            head->previous = newNode;
            head = newNode;
        }
        size++;
    }

    void insertEnd(const Object &x) // insert at the end of the list (push_back).
    {
        if (head == nullptr)
        {
            head = new Node(x);
            tail = head;
            head->previous = tail;
            tail->previous = head;
            head->next = tail;
            tail->next = head;
        }
        else
        {
            Node *newNode = new Node(x);
            newNode->previous = tail;
            newNode->next = head;
            tail->next = newNode;
            head->previous = newNode;
            tail = newNode;
        }
        size++;
    }

    void removeFirst() // remove the first element (pop_front)
    {
        if (empty())
        {
            throw std::runtime_error("List is empty!");
        }
        if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }
        else
        {
            Node *toDel = head;
            head->previous->next = head->next;
            head->next->previous = head->previous;
            head = head->next;
            delete toDel;
            size--;
        }
    }

    void removeLast() // remove the last element (pop_back)
    {
        if (empty())
        {
            throw std::runtime_error("List is empty!");
        }
        if (size == 1)
        {

            delete tail;
            head = nullptr;
            tail = nullptr;
            size = 0;
            return;
        }
        else
        {
            Node *toDel = tail;
            tail->previous->next = tail->next;
            tail->next->previous = tail->previous;
            tail = tail->previous;
            delete toDel;
            size--;
        }
    }

    bool empty() // is the list empty?
    {
        if (size > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
#endif
