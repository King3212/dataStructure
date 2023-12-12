#pragma once
#include<vector>
using namespace std;

template<class T>
class heap
{
private:
    vector<T> array;
    void fixB(int loc){
        
    }
    void fixT(){

    }
public:
    heap(){
        array = vector<T>();
        vector.push_back(T());
    }
    void push(T &x){
        array.push_back(x);
        fixB(array.size()-1)
    }
    T pop(){
        if (empty)
        {
            return T();
        }
        
        T x = array[1];
        fixT();
        return x;
    }
    bool empty(){
        return array.size() == 1;
    }
};


