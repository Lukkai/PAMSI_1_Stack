//#pragma once
#ifndef STACKI_H
#define STACKI_H

#include<iostream>

using namespace std;

/*Definition of StackTab object*/
/*template defines what type and size the object is*/
template <typename T>
class StackTab
{
private:
    T* S;     //stack
    unsigned int size;   //table size
    unsigned int top_ptr;   //top pointer

public:
    StackTab(unsigned int size);  //construcor
    ~StackTab();   //destructor
    StackTab(const StackTab& otherStackTab);

    bool isEmpty();
    bool isFull();
    unsigned int curSize();
    unsigned int maxSize();

    bool push(T data);
    T pop();
    T top();

    void clear();
    void print();

    friend void operator++ (StackTab& myStackTab);
    friend void operator-- (StackTab& myStackTab);

    friend std::ostream& operator<< (std::ostream& out, const StackTab& myStackTab);
};


/*StackTab class methods*/
template <typename T>
StackTab<T>::StackTab(unsigned int size)   //construcor
{
    this->top_ptr = 0;
    this->size = size;
    this->S = new T[size];
}

template <typename T>
StackTab<T>::~StackTab()   //destructor
{
    delete[] this->S;
}

template <typename T>
StackTab<T>::StackTab(const StackTab& otherStackTab)
{
    this->size = otherStackTab.size;
    this->S = new int[size];
    for (int i = 0; i <= otherStackTab.top_ptr; i++)
        this->S[i] = otherStackTab.S[i];
    this->top_ptr = otherStackTab.top_ptr;
}

template <typename T>
bool StackTab<T>::isFull()
{
    if (this->top_ptr >= this->size - 1)
        return true;
    return false;
}

template <typename T>
bool StackTab<T>::isEmpty()
{
    if (this->top_ptr < 0)
        return true;
    return false;
}

template <typename T>
unsigned int StackTab<T>::curSize()
{
    return this->top_ptr;
}
template <typename T>
unsigned int StackTab<T>::maxSize()
{
    return this->size;
}

template <typename T>
bool StackTab<T>::push(T data)
{
    if (isFull())
    {
        cout << "StackTab overflow!" << endl;
        return false;
    }
    this->top_ptr++;
    this->S[this->top_ptr] = data;
    return true;
}

template <typename T>
T StackTab<T>::pop()
{
    if (isEmpty())
    {
        cout << "StackTab underflow!" << endl;
        exit(EXIT_FAILURE);
    }
    this->top_ptr--;
    return this->S[this->top_ptr + 1];
}

template <typename T>
T StackTab<T>::top()
{
    if (isEmpty())
    {
        cout << "StackTab underflow!" << endl;
        exit(EXIT_FAILURE);
    }
    cout << this->S[this->top_ptr] << endl;
    return this->S[this->top_ptr];
}

template <typename T>
void StackTab<T>::clear()
{
    this->top_ptr = 0;
}

template <typename T>
void StackTab<T>::print()
{
    for (unsigned int i = this->top_ptr; i > 0; i--) {
        cout << this->S[i] << endl;
    }
}

template <typename T>
void operator++ (StackTab<T>& myStackTab)
{
    int* tmp = new T[myStackTab.size + 1];
    for (int i = 0; i <= myStackTab.top_ptr; i++)
        tmp[i] = myStackTab.S[i];
    delete[] myStackTab.S;
    myStackTab.S = tmp;
    myStackTab.size++;
}

template <typename T>
void operator-- (StackTab<T>& myStackTab)
{
    int* tmp = new T[myStackTab.size - 1];
    myStackTab.size--;
    if (myStackTab.size == myStackTab.top_ptr)
        myStackTab.top_ptr--;
    for (int i = 0; i <= myStackTab.top_ptr; i++)
        tmp[i] = myStackTab.S[i];
    delete[] myStackTab.S;
    myStackTab.S = tmp;
}

template <typename T>
std::ostream& operator << (std::ostream& out, const StackTab<T>& myStackTab)
{
    std::cout << "StackTab: " << std::endl;
    for (int i = myStackTab.top_ptr; i >= 0; i--)
        std::cout << myStackTab.S[i] << "  ";
    return out;
}


#endif // !stacki_h