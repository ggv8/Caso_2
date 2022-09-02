//  Libraries
//----------------
# pragma once
# include <iostream>
# include <exception>
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

        List()
        {
            size = 0;
            head = new Node<T>();
            tail = new Node<T>();

            head->next = tail;
            tail->prev = head;
        }

        ~List()
        {
            clear();
            delete head;
            delete tail;
        }

        bool isEmpty()
        {
            return !(size);
        }

        int getSize()
        {
            return size;
        }

        T& getFirst()
        {
            return (head->next->data);
        }

        T& getLast()
        {
            return (tail->prev->data);
        }

        T& search(int pIndex)
        {
            if (isEmpty() || pIndex >= size  || pIndex < 0)
            {
                throw std::exception();
            }
            Node<T>* current = head->next;
            for (int position = 0; current != nullptr; position++)
            {
                if (position == pIndex)
                    break;
                current = current->next;
            }
            return current->data;
        }

        void add(const T& pData)
        {
            Node<T>* element = new Node<T>{pData, tail->prev, tail};
            tail->prev->next = element;
            tail->prev = element;
            size++;
        }

        void insert(const T& pData, int pIndex)
        {
            if (size == 0 || pIndex >= size || pIndex < 0)
            {
                add(pData);
                return;
            }

            Node<T>* element = new Node<T>{pData};
            Node<T>* current = head->next;
            for (int position = 0; current != nullptr; position++)
            {
                if (position == pIndex)
                    break;
                current = current->next;
            }

            element->prev = current->prev;
            element->next = current;
            current->prev = current->prev->next = element;
            size++;
        }

        T pop(int pIndex)
        {
            if (isEmpty() || pIndex >= size || pIndex < 0)
            {
                throw std::exception();
            }
            Node<T>* current = head->next;
            for (int position = 0; current != nullptr; position++)
            {
                if (position == pIndex)
                    break;
                current = current->next;
            }

            T dataVal = (current->data);
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            size--;
            return dataVal;
        }

        void clear()
        {
            int start = 0;
            while(! isEmpty())
            {
                pop(start);
            }
        }

        void print()
        {
            std::cout << "[";
            for(int position = 0; position < size; position++)
            {
                std::cout << search(position) << ", ";
            }
            std::cout << "]\n";
        }

};