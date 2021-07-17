#include "list.cpp"
#include <cstdlib>
#include <ctime>
#define  NUMBER 100

int main(){
    srand(time(0));
    Linked_List<int> myIntList; 

    for(int i=0; i<NUMBER; i++){
        if(rand() % 1 == 0) myIntList.addFront(rand() % 1000);
        else myIntList.addRear(rand() % 1000);
    }
    
    cout << "size : "  << myIntList.showListSize() << endl;

    for(int i=0; i<NUMBER; i++){
        if(rand() % 1 == 0) myIntList.deleteFront();
        else  myIntList.deleteRear();
    }
    myIntList.show_AllElement();
}
