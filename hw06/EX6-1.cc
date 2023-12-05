#include<iostream>
#include<vector>
#include<queue>
using namespace std;



void deepfirst(vector<vector<int>>& matrix,int start){
    cout << start << " ";
    for(int i = 0; i < matrix.size(); i++)
    {
        if(i == start){
            matrix[i][i] = 1;
        }
        else if(!matrix[i][i] && matrix[start][i]){
            deepfirst(matrix,i);
        }
    }
}
void deepFirst(vector<vector<int>> matrix,int start){
    vector<vector<int>> cp = matrix;
    deepfirst(cp,start);
}
void wideFirst(vector<vector<int>> matrix,int start){
    int counter = 1;
    queue<int> nodes;
    cout << start << " ";
    nodes.push(start);
    matrix[start][start] = 1;
    while(counter < matrix.size() && !nodes.empty()){
        start = nodes.front();
        nodes.pop();
        for(int i = 0; i < matrix.size(); i++){
            if(i == start){
                continue;
            }else if(!matrix[i][i] && matrix[start][i]){
                cout << i << " ";
                counter ++;
                matrix[i][i] = 1;
                nodes.push(i);
            }
        }
    }
}
int main()
{
    /**
    vector<vector<int>> matrix = {
        {0,1,0,1,0},
        {1,0,1,1,0},
        {0,1,0,1,1},
        {1,1,1,0,0},
        {0,0,1,0,0}
    },matrixCp = matrix;
    deepfirst(matrix,0);
    cout << endl;
    wideFirst(matrixCp,0);
    cout << endl;
    **/
    int x,y,temp;
    while(true){
        cout << "邻接矩阵的行总数和列总数，以输入 -1  -1  来结束整个程序的运行。";
        cin >> x >> y;
        if(x != y) break;
        if(x == -1){
            break;
        }
        cout << "邻接矩阵的每行数据（整数）" << endl;
        vector<vector<int>> matrix;
        for (int i = 0; i < x; i++)
        {
            matrix.push_back(vector<int>());
            for (int j = 0; j < y; j++)
            {
                cin >> temp;
                (matrix[i]).push_back(temp);
            }
        }
        cout << "输入遍历的出发点序号";
        cin  >> temp;

        cout << "deep first:\n" << endl;
        deepFirst(matrix,temp);
        cout << "width first:\n" << endl;
        wideFirst(matrix,temp);
    }
    return 0;
}
