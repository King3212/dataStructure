#include<iostream>
#include<stack>
#include<math.h>
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
        if (waiting.empty())
        {
            int temp = (int)log2(index);
            if (index/2 == pow(2,temp)-1)
            {
                break;
            }
            index = index/2+1;
            continue;
        }
        index = waiting.top();
        cout << arr[index] << " ";
        waiting.pop();
        index = 2*index+1;
    }
    cout << endl;
}


int main(){
    cout << "Please input length:\n";
    int length;
    cin >> length;
    while (length != -1)
    {
        tree<int> data = tree<int>(length);
        cout << "Please input numbers:\n";
        data.input();
        cout << "Input complete! Here is output:\n";
        data.middleOut();
        cout << "Please input length:\n";
        cin >> length;
    }
    return 0;
}
