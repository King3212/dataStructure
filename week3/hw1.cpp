#include<iostream>
#include<stack>
using namespace std;
template <class T>
class tree
{
private:
    T* arr;
    int size;
public:
    tree(int length);
    ~tree();
    void input();
    void middleOut();
};


template <class T>
tree<T>::tree(int size)
{
    arr = new T[size+1];
    this->size = size;
}

template <class T>
tree<T>::~tree()
{
    delete arr;
    size = 0;
}

template <class T>
void tree<T>::input()
{
    for (int i = 1; i <= size; i++)
    {
        cin >> arr[i];
    }
}

template <class T>
void tree<T>::middleOut()
{
    stack<int> waiting;
    int index = 1;
    while (!waiting.empty() || index <= size)
    {
        while (index <= size)
        {
            waiting.push(index);
            index = 2*index;
        }
        cout << arr[waiting.top()] << " ";
        waiting.pop();
        index = waiting.top();
        cout << arr[index] << " ";
        waiting.pop();
        index = 2*index+1;
    }
    cout << endl;
}


int main(){
    int length, temp;
    cin >> length;
    while (temp != -1)
    {
        tree<int> data = tree<int>(length);
        data.input();
        data.middleOut();
    }
    return 0;
}
