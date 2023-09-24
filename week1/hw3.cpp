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
            while(temp != tail){
                cout << temp->data << " ";
                temp = temp-> next;
            }
            cout << temp->data << endl;
        }
        LinkList(T x);
        LinkList();
        bool pushback(T x);
        bool pushforward(T x);
        bool sortedInsert(T x);
        bool deleteItem(T x);


};




template<class T>
bool LinkList<T>::sortedInsert(T x){
    if(size == 0){
        size ++;
        return pushforward(x);
    }
    try {
        if(x < tail->next->data){
            size ++;
            return pushforward(x);
        }else if(x > tail->data){
            return pushback(x);
        }
        Node<T> *temp = tail->next,*keep = tail;
        while(temp!= tail->next->next && x > temp->data){
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
    Node<T> *temp = new Node<T>();
    tail = temp;
    temp->data = x;
    temp->next = tail;
    size = 1;
}

template <class T>
LinkList<T>::LinkList(){
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
        temp -> next = temp;
        size++;
        return true;
    }
    else if(size > 0)
    {
        temp->next = tail->next;
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
    if(size == 0){
        size ++;
        return pushback(x);
    }
    else{
        temp->next = tail->next;
        tail->next = temp;
        size ++;
        return true;
    }
    return false;

}



template <class T>
bool LinkList<T>::deleteItem(T x){
    Node<T> *temp = tail->next,*keep;
    while(temp && temp != tail->next){
        keep = temp;
        if(temp->data == x){
            keep->next = temp->next;
            size--;
            return true;
        }
        temp = temp->next;
    }
    return false;
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
