//  Libraries
//----------------
# include <iostream>
# include <exception>
# include "headers/List.hpp"

//  Structs & Functions
//--------------------------
template<class T>
List<T>::List()
{
    size = 0;
    head = new Node<T>();
    tail = new Node<T>();

    head->next = tail;
    tail->prev = head;
}

template<class T>
List<T>::~List()
{
    clear();
    delete head;
    delete tail;
}

template<class T>
bool List<T>::isEmpty()
{
    return !(size);
}

template<class T>
inline int List<T>::getSize()
{
    return size;
}

template<class T>
T& List<T>::getFirst()
{
    return (head->next->data);
}

template<class T>
T& List<T>::getLast()
{
    return (tail->prev->data);
}

template<class T>
inline T& List<T>::search(int pIndex)
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

template<class T>
void List<T>::add(const T& pData)
{
    Node<T>* element = new Node<T>{pData, tail->prev, tail};
    tail->prev->next = element;
    tail->prev = element;
    size++;
}

template<class T>
void List<T>::insert(const T& pData, int pIndex)
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

template<class T>
T List<T>::pop(int pIndex)
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

template<class T>
void List<T>::clear()
{
    int start = 0;
    while(! isEmpty())
    {
        pop(start);
    }
}

template<class T>
void List<T>::print()
{
    std::cout << "[";
    for(int position = 0; position < size; position++)
    {
        std::cout << search(position) << ", ";
    }
    std::cout << "]\n";
}
