#ifndef LIST_CPP_
#define LIST_CPP_
#include "list.h"
template<typename T>
Linked_List<T>::Linked_List(){
    front = NULL;   rear = NULL;
    list_index = 0;
}
template<typename T>
Linked_List<T>::Linked_List(T item){
    Node<T>* tmp = new Node<T>;
    tmp->item = item;   tmp->link = NULL;
    front = tmp;    rear = tmp;
    list_index = 0;
}
template<typename T>
Linked_List<T>::~Linked_List(){
    Node<T>* tmp = front;
    Node<T>* p;
    cout << "destructor" << endl;
    while(tmp != NULL){
        p = tmp;
        tmp = tmp->link;
        free(p);
    }
}
template<typename T>
bool Linked_List<T>::addRear(T item){
    Node<T>* newNode = new Node<T>;
    if(newNode == NULL){
        cout << "momory error" << endl;
        return false;
    }
    newNode->item = item;
    if(front == NULL && rear == NULL){ //empty
        front = newNode;    rear = newNode;
        newNode->link = NULL;
    }
    else{
        rear->link = newNode;
        newNode->link = NULL;
        rear = newNode;
    }
    list_index++;
    return true;
}
template<typename T>
bool Linked_List<T>::addFront(T item){
    Node<T>* newNode = new Node<T>;
    if(newNode == NULL){
        cout << "memory error" << endl;
        return false;
    }
    newNode->item = item;
    
     if(front == NULL && rear == NULL){ //empty
        front = newNode;    rear = newNode;
        newNode->link = NULL;
     }else{
         newNode->link = front;
         front = newNode;
     }
     list_index++;
     return true;
}
template<typename T>
bool Linked_List<T>::addCertainIndex(T item, int index){
    if(index == 0)
        addFront(item);
    if(index == list_index)
        addRear(item);

    Node<T>* newNode = new Node<T>;
    if(newNode == NULL){
        cout << "memory error" << endl;
        return false;
    }

    newNode->item = item;

    Node<T> *p = front;
    for(int i=0; i<index-1; i++)
        p = p->link;

    newNode->link = p->link;
    p->link = newNode;
    list_index++;
    return true;
}
template <typename T>
T Linked_List<T>::deleteRear(){
    Node<T>* p = front;
    T nodeValue = rear->item;

    for(int i=0; i<list_index-1; i++)
        p = p->link;

    p->link = NULL;
    delete rear;
    rear = p;
    list_index--;
    return nodeValue;
}
template<typename T>
T Linked_List<T>::deleteFront(){
    Node<T>* p = front;
    T nodeValue = front->item;
    front = p->link;
    delete p;
    list_index--;
    return nodeValue;
}
template<typename T>
T Linked_List<T>::deleteCertainIndex(int index){
    Node<T>* p = front;
    if(index == 0)
        deleteFront();
    if(index == list_index)
        deleteRear();
    for(int i=0; i<list_index-1; i++)
        p = p->link;
    p->link = p->link->link;
    T nodeValue = p->link->item;
    list_index--;
    delete(p->link);
    return nodeValue;
};
template<typename T>
int Linked_List<T>::showListSize() const{
    return list_index;
}
template<typename T>
void Linked_List<T>::show_AllElement() const{
    Node<T>* p = front;
    for(int i=0; i<list_index; i++){
        cout << p->item << endl;
        p = p->link;
    }
}

#endif
