//----------------
// Libraries    ||
//----------------

// Validacion de reentrancia y redeclaraciones #ifdef #ifndef #endif

//----------------
// Constants    ||
//----------------

//----------------
// Namespaces   ||
//----------------

//--------------------------------
// Structs, methods, functions  ||
//--------------------------------

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


//----------------
// Main program ||
//----------------