#ifndef LSTACK_HH
#define LSTACK_HH

#include <iostream>

using namespace std;

template <typename T>
class StackList
{
private:
    struct Node                 //element on node struct
    {
        T data;
        Node* next;
    };

    unsigned int num;           // contains number of elements on stack
    Node* LS;                   // node to elements on list, using it as stacks top element

public:
    StackList();                // constructor
    ~StackList();               // destruktor
    bool isEmpty();             // checks if list is isEmpty
    int size();                 // number of elements on list
    void push(T x);             // adds element to list
    T pop();                    // removes element from list
    void print();               // method writing out all elements on current stack
    T top();                    // returns top of stack, lastest element, without removing it
    void clear();               // pops the whole stack
};

template <typename T>
StackList<T>::StackList()
{
    num = 0;
    LS = NULL;
}

template <typename T>
StackList<T>::~StackList()
{
    while (!isEmpty())
        pop();    
}

template <typename T>
int StackList<T>::size()
{
    //cout << "Number of elements on stack:" << num << endl;
    return num;
}

template <typename T>
T StackList<T>::top()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        return LS->data;
    }
    return 0;
}

template <typename T>
bool StackList<T>::isEmpty()
{
    return num == 0;
}

template <typename T>
void StackList<T>::push(T x)
{
    Node* nowy = new Node;
    nowy->data = x;
    nowy->next = LS;
    LS = nowy;
    num = num + 1;    
}

template <typename T>
T StackList<T>::pop()
{
    if (isEmpty())
        cout << "Stack is empty" << endl;
    Node* pom = LS;
    LS = LS->next;
    num = num - 1;
    return pom->data;
}

template <typename T>
void StackList<T>::print()
{
    Node* tmp = LS;
    if(!isEmpty())
        cout << "Stacked elements:" << endl;
    else 
        cout << "Stack is empty" << endl;
    while (tmp != NULL) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}

template <typename T>
void StackList<T>::clear()
{
    if (isEmpty())
        cout << "Stack is empty" << endl;
    else
    {
        while (!isEmpty())
            pop();
    }
}

#endif