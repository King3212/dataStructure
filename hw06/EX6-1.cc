#include<iostream>
#include<vector>
#include<queue>
using namespace std;



void deepfirst(vector<vector<int>> matrix,int start){
    for(int i = 0; i < matrix.size(); i++)
    {
        if(i == start){
            matrix[i][i] = 1;
        }
        else if(!matrix[i][i] && matrix[start][i]){
            cout << i << " ";
            deepfirst(matrix,i);
        }
    }
}

void wideFirst(vector<vector<int>> matrix,int start){
    int counter = 1;
    queue<int> nodes;
    nodes.push(start);
    while(counter < matrix.size() && !nodes.empty()){
        start = nodes.front();
        nodes.pop();
        for(int i = 0; i < matrix.size(); i++){
            if(i == start){
                matrix[i][i] = 1;
            }else if(!matrix[i][i] && matrix[start][i]){
                cout << i << " ";
                counter ++;
                nodes.push(i);
            }
        }
    }

int main()
{

}
