#include "adjList_graph.h"

AdjList_Graph::AdjList_Graph(int num, bool direction){
    num_of_vertices = num;
    adj_list = new GraphNode*[num_of_vertices];
    isDirectional = direction;
    num_of_edges = 0;

    for(int i=0; i<num_of_vertices; i++)
        adj_list[i] = NULL;
}

AdjList_Graph::~AdjList_Graph(){
    GraphNode *p, *q;
    for(int i=0; i<num_of_vertices; i++){
        p = adj_list[i];
            while(p != NULL){
                q = p;
                p = p->next;
                delete q;
            }
            
        
    }
}
GraphNode* AdjList_Graph::create_new_vertice(int num){
    GraphNode *gptr = new GraphNode;
    gptr->num = num;
    gptr->next = NULL;
    return gptr;
}
void AdjList_Graph::connectiong_vertice(const int& vertice1, const int& vertice2){
    if(vertice1 > num_of_vertices || vertice2 > num_of_vertices){
        cout << "The graph is full" << endl;
        return;
    }

    GraphNode *p, *q;

    if(!isDirectional){
        if(!adj_list[vertice1-1])
            adj_list[vertice1-1] = create_new_vertice(vertice2-1);
        else{
            p = adj_list[vertice1-1];
            while(p != NULL){
                q = p;
                p = p->next;
            }
            q->next = create_new_vertice(vertice2-1);
        }
        if(!adj_list[vertice2-1])
            adj_list[vertice2-1] = create_new_vertice(vertice1-1);
        else{
            p = adj_list[vertice2-1];
            while(p != NULL){
                q = p;
                p = p->next;
            }
            q->next = create_new_vertice(vertice1-1);
        }
    }
    else{
        if(!adj_list[vertice1-1])
            adj_list[vertice1-1] = create_new_vertice(vertice2-1);
        else{
            p = adj_list[vertice1-1];
            while(p != NULL){
                q = p;
                p = p->next;
            }
            q->next = create_new_vertice(vertice2-1);
        }
    }
    num_of_edges++;
}
void AdjList_Graph::print_adj_graph() const{
    GraphNode *p;
    for(int i=0; i<num_of_vertices; i++){
        p = adj_list[i];
        while(p){
            cout << p->num + 1 << ' ';
            p = p->next;
        }
        cout << endl;
    }
}