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
    Node<T> *creat(int length);
    void print(Node <T> *p);
    void reverse(Node<T> *node, Node<T> *newHead);
public:
    void Creat(int length = -1);
    void Reverse();
    void Print();
};


template<class T>
Node<T> * recList<T>::creat(int length){
    T x;
    if (length == 0)
    {
        return nullptr;
    }
    cin >> x;
    Node<T> *one = new Node<T>();
    one->data = x;
    one->next = creat(length -1);
    return one;
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
void recList<T>::Creat(int length){
    head = new Node<T>();
    head->next = creat(length);
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
        cout << "Please input length,-1 for exit:\n";
        cin >> length;
        if (length == -1)
        {
            return 0;
        }
        one.Creat(length);
        cout << "Before reverse:\n";
        one.Print();
        one.Reverse();
        cout << "After reverse:\n";
        one.Print();
        cout << endl;
    }
    return 0;
    
}
