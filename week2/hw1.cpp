#include <iostream>
using namespace std;
template<class T>
struct Node
{
    Node<T> *next;
    T *data;
};

template<class T>
class recList
{
private:
    Node<T> *head;
    Node<T> *creat();
public:
    void Creat(T stop);
    void reverse();
};


template<class T>
Node<T> * recList<T>::creat(T stop){
    T x;
    cin >> x;
    if(x == stop){
        return nullptr;
    }
    else{
        Node<T> *one = new Node();
        one->data = x;
        one->next = creat(stop);
        return one;
    }
}

template<class T>
void reclist<T>::Creat(T stop){
    head = new Node();
    head.next = creat(stop);
}

template<class T>
void recList<T>::reverse(){

