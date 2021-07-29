#ifndef _HUFFMAN_CODE_H
#define _HUFFMAN_CODE_H

#include <iostream>
#include <functional>
#include <string>
#include <queue>
using namespace std;

class nodetype{
    public :
        int frequency;
        char ch;
        int length;
        string  symbol;
};
class Huffman_Encoding{
    private :
        string before_encoding;
        string after_encoding;
        nodetype *p_node;
        void encoding();
        void designating_symbol();
    public :
        Huffman_Encoding(const string& be);
        ~Huffman_Encoding(){delete[] p_node;}
        void print_encoded_string() const;
};
#endif