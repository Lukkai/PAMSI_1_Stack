#include "stack.h"

/*Stack class methods*/
template<typename T, int N>
Stack<T, N>::Stack()   //construcor
{
    size = N;
    S = new T[size];
    top_ptr = -1;
}

template<typename T, int N>
Stack<T, N>::~Stack()   //destructor
{
    delete[] S;
}

template<typename T, int N>
bool Stack<T, N>::isFull()
{
    if (top_ptr >= size - 1)
        return true;
    return false;
}

template<typename T, int N>
bool Stack<T, N>::isEmpty()
{
    if (top_ptr < 0)
        return true;
    return false;
}

template<typename T, int N>
bool Stack<T, N>::push(T value)
{
    if (isEmpty())
    {
        std::cout << "Stack overflow!" << std::endl;
        return false;
    }
    top_ptr++;
    S[top_ptr] = value;
    return true;
}

template<typename T, int N>
T Stack<T, N>::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack underflow!" << std::endl;
        exit(EXIT_FAILURE);
    }
    top_ptr--;
    return S[top_ptr + 1];
}

template<typename T, int N>
void operator ++ (Stack<T, N>& myStack)
{
    int* tmp = new T[myStack.size + 1];
    for (int i = 0; i <= myStack.top_ptr; i++)
        tmp[i] = myStack.S[i];
    delete[] myStack.S;
    myStack.S = tmp;
    myStack.size++;
}

template<typename T, int N>
void operator -- (Stack<T, N>& myStack)
{
    int* tmp = new T[myStack.size - 1];
    myStack.size -= 1;
    if (myStack.size == myStack.top_ptr)
        myStack.top_ptr--;
    for (int i = 0; i <= myStack.top_ptr; i++)
        tmp[i] = myStack.S[i];
    delete[] myStack.S;
    myStack.S = tmp;
}

template<typename T, int N>
std::ostream& operator << (std::ostream& out, const Stack<T, N>& myStack)
{
    //std::cout << "Stack: " << std::endl;
    //for (int i = 0; i <= myStack.top_ptr; i++)
    //    std::cout << myStack.S[i] << "  ";
    return out;
}