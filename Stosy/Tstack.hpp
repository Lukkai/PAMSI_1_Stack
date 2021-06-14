//#pragma once
#ifndef TSTACK_HPP
#define TSTACK_HPP

#include<iostream>

using namespace std;

/*Definition of StackTab object*/
/*template defines what type and size the object is*/
template <typename T>
class StackTab
{
private:
    T* S;                                       //stack
    unsigned int size;                          //table size
    unsigned int top_ptr;                       //top pointer

public:
    StackTab(unsigned int size);                //construcor
    ~StackTab();                                //destructor
    StackTab(const StackTab& otherStackTab);

    bool isEmpty() const;                       //boolean method checking if tab is empty
    void curElems();                    //method writing out all current elements on stack
    unsigned int curSize();                     //method returning current number of elements on stack
    unsigned int maxSize();                     //method returning current maximal size of stack tab
    void expand();                              //method expanding 

    void push(T data);
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
StackTab<T>::StackTab(unsigned int size)        //construcor
{
    this->top_ptr = 0;
    this->size = size + 1;
    this->S = new T[this->size];
}

template <typename T>
StackTab<T>::~StackTab()                        //destructor
{
    delete[] this->S;
}

template <typename T>
StackTab<T>::StackTab(const StackTab& otherStackTab)
{
    this->size = otherStackTab.size;
    this->S = new int[this->size];
    for (int i = 0; i <= otherStackTab.size - 1; i++)
        this->S[i] = otherStackTab.S[i];
    this->top_ptr = otherStackTab.top_ptr;
}

//template <typename T>
//bool StackTab<T>::isFull()
//{
//    if (this->top_ptr >= this->size - 1)
//        return true;
//    return false;
//}

template <typename T>
bool StackTab<T>::isEmpty() const
{
    if (this->top_ptr == 0)
        return true;
    return false;
}

template <typename T>
void StackTab<T>::curElems()
{
    for (int i = this->top_ptr; i > 0; i--)
    {
        cout << this->S[i-1] << endl;
    }
    if (this->top_ptr == 0)
    {
        cout << "Empty stack" << endl;
    }
}
template <typename T>
unsigned int StackTab<T>::curSize()
{
    return this->top_ptr;
}

template <typename T>
unsigned int StackTab<T>::maxSize()
{
    return this->size - 1;
}

template <typename T>
void StackTab<T>::expand()
{
    T* tmp = new T[this->size + 1024];          //new tab is extended by 1024 elements
    for (int i = 0; i < this->top_ptr; i++)
    {
        tmp[i] = this->S[i];                    //copy the old stack to the new one
    }

    delete[] this->S;                           //del the old stack

    this->S = tmp;                              //copying temp stack to S stack
    this->size += 1024;                         //how much we expanded our new stack tab maxsize
    cout << "Tab expanded" << endl;
}

template <typename T>
void StackTab<T>::push(T data)
{
    if (this->top_ptr == this->size)
    {
        /*if StackTab is full, enlarge by 100 objects*/
        expand();
        //return false;
    }
    this->S[this->top_ptr++] = data;
    //return true;
}

template <typename T>
T StackTab<T>::pop()
{
    if (isEmpty())
    {
        cout << "StackTab underflow!" << endl;
        exit(EXIT_FAILURE);
    }
    top_ptr--;
    return this->S[this->top_ptr];
}

template <typename T>
T StackTab<T>::top()
{
    if (isEmpty())
    {
        cout << "StackTab empty!" << endl;
        exit(EXIT_FAILURE);
    }
    cout << this->S[this->top_ptr-1] << endl;
    return this->S[this->top_pt-1];
}

template <typename T>
void StackTab<T>::clear()
{
    if (isEmpty())
        cout << "Stos jest pusty" << endl;
    else
    {
        while (!isEmpty())
            pop();
    }
}

template <typename T>
void StackTab<T>::print()
{
    for (unsigned int i = this->top_ptr; i > 0; i--) {
        cout << this->S[i-1] << endl;
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
    for (unsigned int i = myStackTab.top_ptr; i > 0; i--) {
        cout << myStackTab.S[i - 1] << " ";
    }
    return out;
}


#endif // !stacki_h