#include "adjMat_graph.h"

AdjMat_Graph::AdjMat_Graph(int num, bool direction){
    num_of_vertices = num;
    adj_mat = new int*[num_of_vertices];
    for(int i=0; i<num_of_vertices; i++)
        adj_mat[i] = new int[num_of_vertices];
    isDirectional = direction;
    num_of_edges = 0;

    for(int i=0; i<num_of_vertices; i++)
        for(int j=0; j<num_of_vertices; j++)
            adj_mat[i][j] = 0;
}

AdjMat_Graph::~AdjMat_Graph(){
    for(int i=0; i<num_of_vertices; i++)
        delete[] adj_mat[i];
    delete[] adj_mat;
}

void AdjMat_Graph::connecting_vertice(const int& vertice1, const int& vertice2){
    if(vertice1 > num_of_vertices || vertice2 > num_of_vertices){
        cout << "The graph is full" << endl;
        return;
    }
    if(!isDirectional){
        adj_mat[vertice1-1][vertice2-1] = 1;
        adj_mat[vertice2-1][vertice1-1] = 1;
    }
    else{
        adj_mat[vertice1-1][vertice2-1] = 1;
    }
    num_of_edges++;
}
void AdjMat_Graph::print_adj_graph() const{
    for(int i=0; i<num_of_vertices; i++){
        for(int j=0; j<num_of_vertices; j++)
            cout << adj_mat[i][j] << ' ';
        cout << endl;
    }
}