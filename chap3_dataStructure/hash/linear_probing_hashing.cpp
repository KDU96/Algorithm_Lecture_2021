#include <iostream>
#include <vector>
using namespace std;

class Linear_Probing_Hashing{
        private :
                int hash_table_size;
                int *hash_location;
        public :
                Linear_Probing_Hashing(int hts);
                ~Linear_Probing_Hashing();
                void add_element(int key);
                void delete_element(int key);
                void print_all() const;
};
Linear_Probing_Hashing::Linear_Probing_Hashing(int hts)
: hash_table_size(hts)
{
        hash_location = new int[hash_table_size];
        for(int i=0; i<hash_table_size; i++)
                hash_location[i] = -1;
}
Linear_Probing_Hashing::~Linear_Probing_Hashing(){
        delete[] hash_location;
}
void Linear_Probing_Hashing::add_element(int key){
        int hash = key % hash_table_size;
        while(1){
                if(hash_location[hash] == - 1){
                        hash_location[hash] = key;
                        break;
                }
                hash++;
                if(hash == hash_table_size){
                        cout << "hash table is full" << endl;
                        return;
                }
        }
}
void Linear_Probing_Hashing::delete_element(int key){
        int hash = key % hash_table_size;
        while(1){
                if(hash_location[hash] == key){
                        hash_location[key] = -1;
                        return;
                }
                hash++;
                if(hash == hash_table_size){
                        cout << "fail to find the key" << endl;
                        return;
                }
        }
}
void Linear_Probing_Hashing::print_all() const{
        for(int i=0; i<hash_table_size; i++){
                cout << hash_location[i] << '\t';
        }
        cout << endl;
}

int main(){
        Linear_Probing_Hashing my_hash(19);
        int item[] = {1, 19, 5, 1, 18, 3, 8, 9, 14, 7, 5, 24, 1, 13, 16, 12, 5};

        for(int i=0; i<17; i++){
                my_hash.add_element(item[i]);
        }
        my_hash.print_all();

        my_hash.delete_element(19);
        my_hash.delete_element(1);
        my_hash.delete_element(5);
        my_hash.print_all();
}