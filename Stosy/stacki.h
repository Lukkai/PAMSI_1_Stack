//#pragma once
#ifndef STACKI_H
#define STACKI_H

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
        //StackTab(const StackTab& otherStackTab);

        bool isEmpty();
        bool isFull();
        unsigned int curSize();
        unsigned int maxSize();

        bool push(T data);
        T pop();
        T top();

        void clear();
        void print();

        //friend void operator++ (StackTab& myStackTab);
        //friend void operator-- (StackTab& myStackTab);

        //friend std::ostream& operator<< (std::ostream& out, const StackTab& myStackTab);
};

#endif // !stacki_h