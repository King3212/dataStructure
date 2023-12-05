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
    int x,y;
    while(true){
        cin >> x >> y;
        if(x == y && x == -1){
            break;
        }
        vector<vector<int>> matrix;
        while(x > 0){
            matrix
    return 0;
}
