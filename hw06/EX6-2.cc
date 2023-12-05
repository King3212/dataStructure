#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void deepFirst(vector<list<pair<int,int>>> tables,int start);
void wideFirst(vector<list<pair<int,int>>> tables,int start);


int main()
{
    int n,temp;
    while(true){
        cout << "图的结点总数，以输入 -1  来结束整个程序的运行。";
        cin >> n;
        if(n == -1){
            break;
        }
        cout << "分别输入每个结点的邻接点序号，以-1作结束" << endl;
        vector<list<pair<int,int>>> tables;
        for (int i = 0; i < n; i++)
        {
            tables.push_back(list<pair<int,int>>());
            while (true)
            {
                cin >> temp;
                if (temp == -1)
                {
                    break;
                }
                tables[i].push_back(pair<int,int>(temp,0));
            }
            
        }
        


        cout << "输入遍历的出发点序号";
        cin  >> temp;

        cout << "deep first:\n" << endl;
        deepFirst(tables,temp);
        cout << "width first:\n" << endl;
        wideFirst(tables,temp);
    }
}

void deepFirst(vector<list<pair<int,int>>> tables, vector<int> visits,int start){
    if (visits[start]) return;
    cout << start << " ";
    visits[start] = 1;
    for(auto i: tables[start]){
        deepFirst(tables,visits,i.first);
    }
}


void deepFirst(vector<list<pair<int,int>>> tables,int start)
{
    vector<int> visits = vector<int>(tables.size());
    deepFirst(tables,visits,start);
    cout << endl;
}

void wideFirst(vector<list<pair<int,int>>> tables,int start)
{
    vector<int> visits = vector<int>(tables.size());
    visits[start] = 1;
    cout << start << " ";
    
    queue<int> nodes;
    int counter = 1;
    while (counter < tables.size())
    {
        start = nodes.front();
        nodes.pop();
        for(auto i : tables[start]){
            if (!visits[i.first])
            {
                nodes.push(i.first);
                visits[i.first] = 1;
                cout << i.first << " ";
                counter++;
            }
            
        }
    }
    
}
