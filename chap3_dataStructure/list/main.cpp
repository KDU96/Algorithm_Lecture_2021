#include "list.cpp"

int main(){
    Linked_List<int> myIntList;


    myIntList.addRear(1);
    myIntList.addFron(10);
    
    myIntList.show_AllElement();
    cout << "size : "  << myIntList.showListSize() << endl;

    cout << "delete front : " << myIntList.deleteFront() << endl;
    cout << "delete rear : " << myIntList.deleteRear() << endl;
    
}
