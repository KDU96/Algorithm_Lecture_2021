#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#define TRIAL 10
using namespace std;

class Chaining_Hash{
    private :
        list<int> index[11];
    public :
        Chaining_Hash(){}
        ~Chaining_Hash(){}
        void add_node(int key);
        bool delete_node(int key);
        list<int>::iterator search_key(int key) const;
        void print_all_node() const;
};
void Chaining_Hash::add_node(int key){
    int div = key % 11;
    index[div].push_back(key);
}
bool Chaining_Hash::delete_node(int key){
    list<int>::iterator iter = search_key(key);
    if(iter != static_cast<list<int>::iterator>(0)){
        index[key % 11].erase(iter);
        return true;
    }
    return false;
}
list<int>::iterator Chaining_Hash::search_key(int key) const{
    int div = key % 11;
    typename list<int>::iterator iter;
    iter = index[0].begin();
    #if 1
    for(iter = index[div].begin(); iter != index[div].end(); iter++)
        if(*iter == key)
            return iter;
    #endif
    return static_cast<list<int>::iterator>(0);
}
#if 1
void Chaining_Hash::print_all_node() const{
    typename list<int>::iterator iter;
    
        #if 1
        for(iter = index[i].begin(); iter != index[i].end(); iter++){
            cout <<*iter << '\t';
        }
        #endif
        cout << endl;
 }


#endif
int main(){
    srand(time(0));
    Chaining_Hash myHash;

    for(int i=0; i<TRIAL; i++){
        myHash.add_node(rand() % 100);
    }
   myHash.print_all_node();
}