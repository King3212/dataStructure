#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define int_max (32767)


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
    if (start >= n || start < 0)
    {
        cerr << "起始节点不在图内！" << endl;
        return;
    }

    vector<int> dist = matrix[start];
    int pos = 0;
    int Min = 0;
    matrix[start][start] = 1;
    

    for (int i = 0; i < n; i++)
    {
        Min = int_max;
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
    
    for (int end = 0; end < n; end++)
    {
        cout << start << " --> " << end << " : ";
        if (dist[end] == int_max)
        {
            cout << "无通路";
        }else{
            cout << dist[end];
        }
        cout  << endl;
    }
    
}   

int main()
{
    int x,y,temp;
    while(true){
        cout << "邻接矩阵的行总数和列总数，以输入 -1  -1  来结束整个程序的运行。" << endl;
        cin >> x >> y;
        if (y == -1 && x == -1)
        {
            break;
        }else if (x != y)
        {
            break;
        }
        vector<vector<int>> matrix;
        
        cout << "邻接矩阵的每行数据（非负整数）" << endl;
        for (int i = 0; i < x; i++)
        {
            matrix.push_back(vector<int>());
            for (int j = 0; j < y; j++)
            {
                cin >> temp;
                while (temp < 0)
                {
                    cerr << "输入为负数，请重新输入！" << endl;
                    cin >> temp;
                }
                
                
                (matrix[i]).push_back(temp);
            }
            
        }

        if(x > 0){
            cout << "输入源点对应的结点序号：\n";
            cin >> temp;
            Dijkstra(matrix,temp);
        }
        
    }
}