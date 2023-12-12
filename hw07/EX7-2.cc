#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct Edge {
    int start, end, weight;
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
    void print(){
        cout << start << " --> " << end << " : " << weight << endl;
    }
};



void Dijkstra(vector<vector<int>> matrix, int start){
    int n = matrix.size();
    vector<int> dist = matrix[start];
    int pos = 0;
    stack<int> nodes;
    int Min = 0;
    matrix[start][start] = 1;
    

    for (int i = 0; i < n; i++)
    {
        Min = INT16_MAX;
        for (int k = 0; k < n; k++)
        {
            if (matrix[k][k] == 0 && dist[k] < Min)
            {
                pos = k;
                Min = dist[k];
            }
            
        }
        matrix[pos][pos] = 1;
        for (int j = 0; j < n; j++)
        {
            if (matrix[j][j] == 0 && matrix[pos][j]+Min < dist[j])
            {
                dist[j] = matrix[pos][j]+Min;
            }
            
        }
        
    }
    
}   

