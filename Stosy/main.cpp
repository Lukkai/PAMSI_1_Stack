#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include "TStack.hpp"
//#include "LStack.hpp"

using namespace std;

int main()
{
    StackTab<int> stos_2(10);
    //for (int i = 0; i < 10; i++)
    //    s1.push(i);
    //std::cout << s1.isEmpty() << std::endl;
    //std::cout << s1 << std::endl;
    //s1.print();

    for (unsigned int i = 0; i < stos_2.maxSize(); i++) 
    {
        stos_2.push((int)pow(i, 2));
    }
    stos_2.print();

    printf("*********************\n");
    stos_2.curElems();
    printf("*********************\n");
    stos_2.clear();

    printf("*********************\n");
    for (unsigned int i = 0; i < stos_2.maxSize(); i++)
    {
        stos_2.push((int)pow(i, 2));
    }
    stos_2.print();

    printf("*********************\n");
    for (unsigned int i = 0; i < 10; i++) {
        stos_2.push((int)pow(i, 3));
    }

    printf("*********************\n");
    //stos_2.print();
    while (!stos_2.isEmpty()) {
        cout << stos_2.pop() << endl;
    }

    cin.get();
}

