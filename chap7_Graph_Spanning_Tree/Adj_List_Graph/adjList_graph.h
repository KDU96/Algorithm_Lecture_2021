#ifndef __ADJLIST_GRAPH_H__
#define __ADJLIST_GRAPH_H__

#include <iostream>
using namespace std;

class GraphNode{
    public :
        int num;
        GraphNode* next;
};

class AdjList_Graph{
    private :
        GraphNode **adj_list;
        int num_of_vertices;
        int num_of_edges;
        bool isDirectional;
        GraphNode* create_new_vertice(int num);
    public :
        AdjList_Graph(int num, bool direction);
        ~AdjList_Graph();
        void connectiong_vertice(const int& vertice1, const int& vertice2);
        void print_adj_graph() const;
};
#endif