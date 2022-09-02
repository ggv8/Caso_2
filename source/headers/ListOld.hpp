//  Libraries
//----------------
# pragma once
# include "Node.hpp"

//  Structs & Functions
//--------------------------
template<class T>
class List
{
    private:

        int size;
        Node<T>* head;
        Node<T>* tail;
        
    public:

        List();

        ~List();

        bool isEmpty();

        int getSize();

        T& getFirst();

        T& getLast();

        T& search(int pIndex);

        void add(const T& pData);

        void insert(const T& pData, int pIndex);

        T pop(int pIndex);

        void clear();

        void print();

};