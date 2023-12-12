#pragma once
#include<vector>
using namespace std;

template<class T>
class maxHeap
{
private:
    vector<T> array;
    void fixB(int loc){
        if (loc == 1) return;
        else{
            int parent = loc / 2;
            if (array[parent] < arr[loc])
            {
                swap(array[parent],array[loc]);
                fixB(parent);
            }
            return;
        }
        
    }
    void fixT(int loc = 1){
        if (loc >= array.size())
        {
            return;
        }
        
        int leftChild = loc*2;
        int rightChild = loc*2+1;
        if (arr[leftChild] > arr[rightChild])
        {
            swap(arr[leftChild],arr[rightChild]);
        }
        if (arr[rightChild] > array[loc])
        {
            swap(arr[rightChild],array[loc]);
            fixT(rightChild);
        }
        
        
    }
public:
    maxHeap(){
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
        swap(array[1],array[array.size()-1]);
        array.pop_back();
        fixT();
        return x;
    }
    bool empty(){
        return array.size() == 1;
    }
};


