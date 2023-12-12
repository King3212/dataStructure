
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;




struct Edge {
    int start, end, weight;
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
    void print(){
        cout << start << " - " << end << " : " << weight << endl;
    }
};

class DisjointSet
{
public:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n){
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
        }
        rank = vector<int>(n,0);
    }
    int find(int x){
        while (parent[x] != x)
        {
            x = parent[x];
        }
        return x;
    }
    void unionSets(int x, int y){
        x = find(x);
        y = find(y);
        if (rank[x] < rank[y])
        {
            parent[x] = y;
        }else if(rank[x] > rank[y]){
            parent[y] = x;
        }else{
            parent[x] = y;
            rank[y] ++;
        }
        
    }
    bool sameSet(int x,int y){
        return find(x) == find(y);
    }
};


vector<Edge> prim(vector<vector<int>> matrix,int n){
    vector<Edge> result;
    int addNow = 0;
    int counter = 1;
    priority_queue<Edge> edges;
    Edge one;


    while (counter < n)
    {
        matrix[addNow][addNow] = 1;
        for (int i = 0; i < n; i++)
        {
            if (i == addNow)
            {
                continue;
            }
            if (!matrix[i][i])
            {
                one.start = addNow;
                one.end = i;
                one.weight = matrix[i][addNow];
                edges.push(one);
            }
            
        }

        while (true)
        {
            one = edges.top();
            edges.pop();
            if (!matrix[one.end][one.end])
            {
                break;
            }
        }
        result.push_back(one);
        addNow = one.end;
        counter++;
    }
    return result;
}

vector<Edge> kruskal(vector<Edge>& edges, int numsV){
    vector<Edge> result;
    priority_queue<Edge> heap;
    for(auto i : edges){
        heap.push(i);
    }
    DisjointSet sets = DisjointSet(numsV);
    Edge one;
    while (numsV > 1)
    {
        one = heap.top();
        heap.pop();
        if (sets.sameSet(one.start,one.end))
        {
            continue;
        }else{
            result.push_back(one);
            sets.unionSets(one.start,one.end);
            numsV--;
        }
        
    }
    return result;
    
}


int main(int argc, char const *argv[])
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
        vector<Edge> edges;
        Edge edge;
        cout << "邻接矩阵的每行数据（整数）" << endl;
        for (int i = 0; i < x; i++)
        {
            matrix.push_back(vector<int>());
            for (int j = 0; j < y; j++)
            {
                cin >> edge.weight;
                edge.start = i;
                (matrix[i]).push_back(edge.weight);
                edge.end = j;
                edges.push_back(edge);
            }
            
        }
        cout << "卡鲁斯卡尔求最小生成树的结果序列"<< endl;
        for(auto i : kruskal(edges,x)){
            i.print();
        }
        
        cout << "普里姆求最小生成树的结果序列"<< endl;
        for(auto i : prim(matrix, x)){
            i.print();
        }
    }
    return 0;
}



