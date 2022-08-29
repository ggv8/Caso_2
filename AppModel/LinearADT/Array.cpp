//  Structs & Functions
//--------------------------
template<class T>
struct Array
{
    int size;
    T* elements;

    T& get(int pIndex)
    {
        return elements[pIndex];
    }
};