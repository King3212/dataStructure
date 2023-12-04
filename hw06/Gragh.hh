#include<vector>
#include<iostream>
using namespace std;
class Gragh
{
protected:
    int Size;
    vector<vector<int>> matrix;
public:
    Gragh(vector<vector<int>> matrix);
    ~Gragh();
    void print();
    int size();
};

Gragh::Gragh(vector<vector<int>> matrix)
{
    this->matrix = matrix;
    this->Size = matrix.size();
}

Gragh::~Gragh()
{
}

inline void Gragh::print()
{
    for(auto i : matrix){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

inline int Gragh::size()
{
    return Size;
}
