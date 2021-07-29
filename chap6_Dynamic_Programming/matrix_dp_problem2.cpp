#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define     ROW     9
#define     COL     9
#define     MAX_ROUTE 16

char maze[ROW][COL] = {{'d', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'},
                       {'o', 'o', 'o', 'o', 'o', 'c', 'o', 'o', 'o'},
                       {'o', 'c', 'o', 'o', 'c', 'o', 'o', 'o', 'o'},
                       {'o', 'o', 'o', 'o', 'o', 'o', 'c', 'o', 'o'},
                       {'o', 'c', 'o', 'c', 'o', 'o', 'o', 'o', 'o'},
                       {'o', 'o', 'o', 'o', 'c', 'o', 'o', 'o', 'o'},
                       {'c', 'o', 'o', 'o', 'o', 'o', 'o', 'c', 'o'},
                       {'o', 'o', 'o', 'o', 'o', 'c', 'o', 'o', 'o'},
                       {'o', 'o', 'c', 'o', 'o', 'o', 'o', 'o', 'a'}};

class MatIndex{
    public :
        int row;
        int col;
};
int maxCheeze(MatIndex destination){
    MatIndex idx = {0, 0};
    vector<MatIndex> course;
    course.push_back(idx);
    
    for(int i=1; i<ROW - idx.row - 1; i++)
        for(int j=idx.row; j <= i && j < ROW; j++)
            for(int k=idx.col; k <=i && j < COL; k++)
                if(maze[j][j] == 'c' || maze[i][j] == 'd'){
                    idx.row = i;
                    idx.col = j;
                    break;
                }

    }
}

