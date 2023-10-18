#include <iostream>
using namespace std;
template<class T>
struct Node
{
    Node<T> *next;
    T data;
};

template<class T>
class recList
{
private:
    Node<T> *head;
    Node<T> *creat(T stop,int length);
    void print(Node <T> *p);
    void reverse(Node<T> *node, Node<T> *newHead);
public:
    void Creat(T stop, int length = -1);
    void Reverse();
    void Print();
};


template<class T>
Node<T> * recList<T>::creat(T stop,int length){
    T x;
    if (length == 0)
    {
        return nullptr;
    }
    cin >> x;
    if(x == stop){
        return nullptr;
    }
    else{
        Node<T> *one = new Node<T>();
        one->data = x;
        one->next = creat(stop, length -1);
        return one;
    }
}

template <class T>
void recList<T>::print(Node <T> *p)
{
    if (p == nullptr)
    {
        cout << endl;
        return;
    }
    
    cout << p->data << " ";
    print(p->next);
}

template <class T>
void recList<T>::reverse(Node<T> *node,Node<T> *newHead)
{
    if (node == nullptr)
    {
        return;
    }
    Node<T> *temp1 = newHead->next, *temp2 = node->next;
    newHead->next = node;
    node->next = temp1;
    reverse(temp2,newHead);
}

template<class T>
void recList<T>::Creat(T stop, int length){
    head = new Node<T>();
    head->next = creat(stop,length);
}

template<class T>
void recList<T>::Reverse(){
    Node<T> *newHead = new Node<T>();
    newHead->next = nullptr;
    reverse(head->next,newHead);
    delete head;
    head = newHead;
}

template <class T>
void recList<T>::Print()
{
    print(head->next);
}


int main()
{
    while (true)
    {
        recList<int> one;
        int length;
        cin >> length;
        if (length == -1)
        {
            return 0;
        }
        cout << "Please input length,-1 for exit:\n";
        one.Creat(-1,length);
        cout << "Before reverse:\n";
        one.Print();
        one.Reverse();
        cout << "After reverse:\n";
        one.Print();
        cout << endl;
    }
    return 0;
    
}
