#include <iostream>
using namespace std;

template <class T>
struct Node
{
    Node<T> *next;
    T data;
};

template<class T>
class LinkList{
    private:
        Node<T> *tail;
        int size;
    public:
        void show(){
            Node<T> *temp = tail->next;
            while(temp){
                cout << temp->data << " ";
                temp = temp-> next;
            }
            cout << endl;
        }
        LinkList(T x);
        LinkList();
        bool pushback(T x);
        bool pushforward(T x);
        bool sortedInsert(T x);

};

template<class T>
bool LinkList<T>::sortedInsert(T x){
    if(size == 0){
        pushforward(x);
        size ++;
        return true;
    }
    try {
        if(x < head->data){
            pushforward(x);
            size ++;
            return true;
        }
        Node<T> *temp = head,*keep = head;
        while(temp && x > temp->data){
            keep = temp;
            temp = temp->next;
        }
        Node<T> *newOne = new Node<T>();
        newOne->data = x;
        newOne->next = keep->next; 
        keep->next = newOne;
        if(keep == tail){
            tail = newOne;
        }
        size++;
        return true;
    }catch(exception e){
        return false;
    }
}
template <class T>
LinkList<T>::LinkList(T x){
    head = new Node<T>();
    head->next = nullptr;
    Node<T> *temp = new Node<T>();
    temp->data = x;
    temp->next = nullptr;
    head->next = temp;
    tail->next = temp;
    size = 1;
}

template <class T>
LinkList<T>::LinkList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
bool LinkList<T>::pushback(T x){
    Node<T> *temp = new Node<T>();
    temp->data = x;
    if(tail == nullptr)
    {
        tail = temp;
        head = temp;
        size++;
        return true;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        size++;
        return true;
    }
    return false;
}

template <class T>
bool LinkList<T>::pushforward(T x){
    Node<T> *temp = new Node<T>();
    temp->data = x;
    temp->next = head;
    head = temp;
    size++;
    return true;
}

int main(){
    LinkList<int> one = LinkList<int>();
    int x = 0;
    cin >> x;
    while(x != -1){
        one.pushback(x);
        cin >> x;
    }
    one.show();
    cin >> x;
    one.sortedInsert(x);
    one.show();
    return 0;
}
