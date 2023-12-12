#include<iostream>
#include<vector>
#include<list>
#include<stack>

using namespace std;

void topu_sort(vector<list<int>> tables){
    stack<int> zeroVs;
    int V;
    int n = tables.size();
    vector<int> nodes = vector<int>(n);

    for (list<int> aList : tables)
    {
        for (int x : aList){
            nodes[x] += 1;
        }
    }
    for (int i = 0; i < n; i++){
        if (!nodes[i]) zeroVs.push(i);
    }

    vector<int> result;

    while(!zeroVs.empty()){
        V = zeroVs.top();
        result.push_back(V);
        zeroVs.pop();
        for (int node : tables[V])
        {
            nodes[node]-=1;
            if (nodes[node] == 0){
                zeroVs.push(node);
            }
        }
        
    }
    
    if (result.size() < n)
    {
        cout << "该图存在回路";
    }else{
        for(int x : result){
            cout << x << " ";
        }
    }
    cout  << endl;
}


int main(){
    int n,temp;
    while(true){
        cout << "图的结点总数，以输入 -1 来结束整个程序的运行。\n";
        cin >> n;
        if(n == -1){
            break;
        }
        cout << "分别输入每个结点所邻接到的邻接点序号，以-1作结束" << endl;
        vector<list<int>> tables;
        for (int i = 0; i < n; i++)
        {
            tables.push_back(list<int>());
            while (true)
            {
                cin >> temp;
                if (temp == -1)
                {
                    break;
                }
                tables[i].push_back(temp);
            }
            
        }
        topu_sort(tables);
        cout << endl;
    }
}