//  Libraries
//----------------
# include <iostream>
# include <exception>
# include "Node.cpp"

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
            Node<T>* search = head->next;
            for (int position = 0; search != nullptr; position++)
            {
                if (position == pIndex)
                    break;
                search = search->next;
            }
            return search->data;
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
            Node<T>* search = head->next;
            for (int position = 0; search != nullptr; position++)
            {
                if (position == pIndex)
                    break;
                search = search->next;
            }

            element->prev = search->prev;
            element->next = search;
            search->prev = search->prev->next = element;
            size++;
        }

        T pop(int pIndex)
        {
            if (isEmpty() || pIndex >= size || pIndex < 0)
            {
                throw std::exception();
            }
            Node<T>* search = head->next;
            for (int position = 0; search != nullptr; position++)
            {
                if (position == pIndex)
                    break;
                search = search->next;
            }

            T dataVal = (search->data);
            search->prev->next = search->next;
            search->next->prev = search->prev;
            delete search;
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