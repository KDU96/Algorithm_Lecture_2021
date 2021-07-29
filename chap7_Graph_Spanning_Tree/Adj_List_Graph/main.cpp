#include "adjList_graph.h"

int main(){
    AdjList_Graph g1(5, false);
    g1.connectiong_vertice(1, 5);
    g1.connectiong_vertice(1, 2);
    g1.connectiong_vertice(2, 3);
    g1.connectiong_vertice(2, 4);
    g1.connectiong_vertice(2, 5);
    g1.connectiong_vertice(3, 4);
    g1.connectiong_vertice(4, 5);

    cout << "Graph 1" << endl;
    g1.print_adj_graph();

    AdjList_Graph g2(6, true);
    g2.connectiong_vertice(1, 2);
    g2.connectiong_vertice(1, 4);
    g2.connectiong_vertice(2, 5);
    g2.connectiong_vertice(3, 6);
    g2.connectiong_vertice(3, 5);
    g2.connectiong_vertice(4, 2);
    g2.connectiong_vertice(5, 4);
    g2.connectiong_vertice(6, 6);

    cout << endl;
    cout << "Graph 2" << endl;
    g2.print_adj_graph();
}