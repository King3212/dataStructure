
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 定义边的结构体
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
        cin >> x >> y;
        if (y == -1 && x == -1)
        {
            break;
        }else if (x != y)
        {
            break;
        }
        vector<Edge> edges;
        Edge edge;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cin >> edge.weight;
                edge.start = i;
                edge.end = j;
                edges.push_back(edge);
            }
            
        }
        for(auto i : kruskal(edges,x)){
            i.print();
        }

        
    }
    
    cout << "prim:" << endl;

    int n = 4;
    vector<vector<int>> matrix = {
    {0, 2, 0, 6},
    {2, 0, 3, 8},
    {0, 3, 0, 0},
    {6, 8, 0, 0}
    };

    for(auto i : prim(matrix, n)){
        i.print();
    }
    
    return 0;
}



