#ifndef _ADJ_MAT_GRAPH_H_
#define _ADJ_MAT_GRAPH_H_
#include <iostream>
using namespace std;
class AdjMat_Graph{
    private :
        int **adj_mat;
        int num_of_vertices;
        int num_of_edges;
        bool isDirectional;
    public :
        AdjMat_Graph(int num, bool direction);
        ~AdjMat_Graph();
        void connecting_vertice(const int& vertice1, const int& vectice2);
        void print_adj_graph() const;
};
#endif