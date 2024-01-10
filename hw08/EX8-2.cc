#include<vector>
#include<iostream>
using namespace std;

template<class T>
class maxHeap
{
private:
    vector<T> array;
    void fixB(int loc){//向上
        if (loc == 1) return;
        else{
            int parent = loc / 2;
            if (array[parent] < array[loc])
            {
                swap(array[parent],array[loc]);
                fixB(parent);
            }
            return;
        }
    }
    void fixT(int loc = 1){//向下
        if (loc >= array.size())
        {
            return;
        }
        
        int leftChild = loc*2;
        int rightChild = loc*2+1;
        if (leftChild >= array.size())
        {
            return;
        }else if(rightChild >= array.size()){
            if (array[leftChild] > array[loc])
            {
                swap(array[leftChild], array[loc]);
            }
            return;
        }
        
        
        int biggerOne = leftChild;
        if (array[leftChild] < array[rightChild])
        {
            biggerOne = rightChild;
        }
        if (array[biggerOne] > array[loc])
        {
            swap(array[biggerOne], array[loc]);
            fixT(biggerOne);
        }
    }
public:
    maxHeap(){
        array = vector<T>();
        array.push_back(T());
    }
    void push(T &x){
        array.push_back(x);
        fixB(array.size()-1);
    }
    T pop(){
        if (array.empty())
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

void heapSort(int *array,int size){
    maxHeap<int> one = maxHeap<int>(); 
    for (int i = 0; i < size; i++)
    {
        one.push(array[i]);
    }
    for (int i = 0; i < size; i++)
    {
        array[size-i-1] = one.pop();
    }
    
}

int main(){
    int *array, size;
    while (true)
    {
        cout << "待排序的元素个数，以输入 -1   来结束整个程序的运行。" << endl;
        cin >> size;
        if (size < 0) break;
        array = new int[size];
        cout << "输入待排序的每一个元素（整数）" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }
        cout << endl << "排序前的元素序列" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }

        heapSort(array,size);

        cout << endl << "排序前的元素序列" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        delete[] array;
        cout << endl << endl;
    }
    
}
