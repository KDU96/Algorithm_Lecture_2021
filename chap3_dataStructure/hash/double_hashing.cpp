#include <iostream>
#include <vector>
using namespace std;

class Double_Hashing{
    private :
        vector<int> hash;
        int hashTable_size;
        int item_nums;
    public :
        Double_Hashing(int size);
        ~Double_Hashing(){}
        void add_item(int key);
        void delete_item(int key);
        void print_all() const;
};

Double_Hashing::Double_Hashing(int size)
:hashTable_size(size), item_nums(0){
    hash.assign(size, -1);
}
void Double_Hashing::add_item(int key){
    if(item_nums >= hashTable_size){
        cout << "hash table is full" << endl;
        return;
    }
    int hash1 = key % hashTable_size;
    int hash2 = hashTable_size/2 - (key % (hashTable_size/2));
    int index = hash1;

    while(hash.at(index) != -1){
        index = (index + hash2) % hashTable_size;
    }
          hash.at(index) = key;
          item_nums++;
}
void Double_Hashing::delete_item(int key){
    int count = item_nums;
    int hash1 = key % hashTable_size;
    int hash2 = hashTable_size / 2 - (key % (hashTable_size/2));
    int index = hash1;

    while(count > 0){
        if(hash.at(index) == key){
            hash.at(index) = -1;
            item_nums--;
            return;
        }
        count--;
    }
    cout << "there is no item in the hash table" << endl;
    return;
}
void Double_Hashing::print_all() const{
    for(int i=0; i<hashTable_size; i++)
        cout << hash.at(i) << ' ';
    cout << endl;
}

int main(){
    Double_Hashing my_hash(19);
    int item[] = {1, 19, 5, 1, 18, 3, 8, 9, 14, 7, 5, 24, 1, 13, 16, 12, 5};

    for(int i=0; i<17; i++){
            my_hash.add_item(item[i]);
    }
    my_hash.print_all();

    my_hash.delete_item(19);
    my_hash.delete_item(1);
    my_hash.delete_item(5);
    my_hash.print_all();    
}