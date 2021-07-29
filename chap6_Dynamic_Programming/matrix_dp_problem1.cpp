#include <iostream>
#include <vector>
#define     ROW     3
#define     COL     3
using namespace std;

class MatIndex{
    public :
        int row;
        int col;
};


MatIndex find_next_location(MatIndex idx, int mat[ROW][COL]){
    if(idx.col-1 < 0){
        if(mat[idx.row+1][idx.col] < mat[idx.row+1][idx.col+1]){
            MatIndex tmp;   tmp.row = idx.row+1;    tmp.col = idx.col+1;
            return tmp;
        }
        else{
            MatIndex tmp;   tmp.row = idx.row+1;    tmp.col = idx.col;
            return tmp;
        }
    }
    else if(idx.col > COL){
        if(mat[idx.row+1][idx.col] < mat[idx.row+1][idx.col-1]){
            MatIndex tmp;   tmp.row = idx.row+1;    tmp.col = idx.col-1;
            return tmp;
        }
        else{
            MatIndex tmp;   tmp.row = idx.row+1;    tmp.col = idx.col;
        }
    }
    else{
        if(mat[idx.row+1][idx.col-1] > mat[idx.row+1][idx.col] && mat[idx.row+1][idx.col-1] > mat[idx.row+1][idx.col+1]){
            MatIndex tmp;   tmp.row = idx.row+1;    tmp.col = idx.col-1;
            return tmp;
        }
        else if(mat[idx.row+1][idx.col] > mat[idx.row+1][idx.col-1] && mat[idx.row+1][idx.col] > mat[idx.row+1][idx.col+1]){
            MatIndex tmp;   tmp.row = idx.row+1;    tmp.col = idx.col;
            return tmp;
        }
        else{
            MatIndex tmp;   tmp.row = idx.row+1;    tmp.col = idx.col+1;
            return tmp;
        }

    }
}

int find_optimal_route(int row, int col, int mat[][COL]){
    int i, j, sum = 0;      //i : col index, j row index
    MatIndex idx;   idx.row = row;  idx.col = col;
    vector<int> log(ROW, -1);
    log.at(0) = mat[row][col];

    for(i=1; i<ROW; i++){
        idx = find_next_location(idx, mat);
        log.at(i) = log.at(i-1) + mat[idx.row][idx.col];
    }
    return log.at(ROW-1);
}

int main(){
    int matrix[ROW][COL] = {{3,   4,    9},
                            {223, 7,    8},
                            {2,   51, -23}};
    cout << "result : " << find_optimal_route(0, 0, matrix) << endl;
}