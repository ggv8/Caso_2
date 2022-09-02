//  Structs & Functions
//--------------------------
# pragma once
template<class T>
struct Node
{
    T data;
    Node<T> *prev;
    Node<T> *next;

    Node(const T& pData = T(), Node* pPrev = nullptr, Node* pNext = nullptr)
    : data(pData), prev(pPrev), next(pNext)
    {}
};