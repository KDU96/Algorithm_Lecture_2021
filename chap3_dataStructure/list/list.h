#ifndef LIST_H_
#define LIST_H_

#include <iostream>
using namespace std;

template<typename T>
class Linked_List;

template <typename T>
class Node{
    public :
        T item;
        Node* link;
};

template <typename T>
class Linked_List{
    private :
        Node<T>* front;
        Node<T>* rear;
        int list_index;
    public :
        Linked_List();
        Linked_List(T first_item);
        ~Linked_List();
        bool addRear(T item);
        bool addFront(T item);
        bool addCertainIndex(T item, int index);
        T deleteRear();
        T deleteFront();
        T deleteCertainIndex(int index);
        int showListSize() const;
        void show_AllElement() const;
};
#endif

