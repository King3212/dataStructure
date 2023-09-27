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
        Node<T> *head;
        Node<T> *tail;
        int size;
    public:
        void show(){
            Node<T> *temp = head->next;
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
        T get(int x);
        void clear();

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


template<class T>
T LinkList<T>::get(int x)
{
    Node<T> *temp = head->next;

    for (int i = 0; i < x; i++)
    {
        if(temp == nullptr) return -1;
        temp = temp->next;
    }
    if(temp == nullptr) return -1;
    return temp->data;
}

template <class T>
void LinkList<T>::clear()
{
    Node<T> *temp = head->next,*next = nullptr;
    while (temp)
    {
        
        if (temp->next != nullptr)
        {
            next = temp->next;
        }
        delete temp;
        temp = next;
    }
    head->next = nullptr;
    tail->next = nullptr;
}

template <class T>
LinkList<T>::LinkList(T x){
    head = new Node<T>();
    head->next = nullptr;
    tail = new Node<T>();
    Node<T> *temp = new Node<T>();
    temp->data = x;
    temp->next = nullptr;
    head->next = temp;
    tail->next = temp;
    size = 1;
}

template <class T>
LinkList<T>::LinkList(){
    head = new Node<T>();
    head->next = nullptr;
    tail = new Node<T>();
    tail->next = nullptr;
    size = 0;
}

template <class T>
bool LinkList<T>::pushback(T x){
    Node<T> *temp = new Node<T>();
    temp->data = x;
    if(tail->next == nullptr)
    {
        tail->next = temp;
        head->next = temp;
        size++;
        return true;
    }
    else
    {
        tail->next->next = temp;
        tail->next = temp;
        size++;
        return true;
    }
    return false;
}

template <class T>
bool LinkList<T>::pushforward(T x){
    Node<T> *temp = new Node<T>();
    temp->data = x;
    temp->next = 0;
    head->next = temp;
    if (!tail->next)
    {
        tail->next = temp;
    }
    
    size++;
    return true;
}

#include<vector>
bool test(){
    /*
    *test the sortedInsert()
    */
    // default size = 5
    vector<int> testData = {12,23,34,45,56};
    int insertedOne = 33;

    //test 1
    //test no item
    cout << "test1:" << endl;
    LinkList<int> *one = new LinkList<int>();
    one->show();
    cout << "insert:" << insertedOne << endl << "finish:" << endl;
    one->sortedInsert(insertedOne);
    one->show();
    if (one->get(0) != insertedOne) return false;
    one->clear();
    cout << "test1 pass" << endl << endl;

    //test 2
    //test have items, insert last one
    cout << "test2:" << endl;
    for (int i = 0; i < 2; i++)
    {
        one->pushback(testData[i]);
    }
    one->show();
    cout << "insert:" << insertedOne << endl << "finish:" << endl;
    one->sortedInsert(insertedOne);
    one->show();
    if (one->get(2) != insertedOne) return false;
    one->clear();
    cout << "test2 pass" << endl << endl;
    
    //test 3
    //test have items, insert middle
    cout << "test3:" << endl;
    for (int i = 0; i < 4; i++)
    {
        one->pushback(testData[i]);
    }
    one->show();
    cout << "insert:" << insertedOne << endl << "finish:" << endl;
    one->sortedInsert(insertedOne);
    one->show();
    if (one->get(2) != insertedOne) return false;
    one->clear();
    cout << "test3 pass" << endl << endl;
    
    //test 4
    //test have items, insert first location
    cout << "test4:" << endl;
    for (int i = 2; i < 5; i++)
    {
        one->pushback(testData[i]);
    }
    one->show();
    cout << "insert:" << insertedOne << endl << "finish:" << endl;
    one->sortedInsert(insertedOne);
    one->show();
    if (one->get(0) != insertedOne) return false;
    one->clear();
    cout << "test4 pass" << endl << endl;


    //test 5
    //LinkList is full, insert
    cout << "test5:" << endl;
    for (int i = 0; i < 5; i++)
    {
        one->pushback(testData[i]);
    }
    one->show();
    cout << "insert:" << insertedOne << endl << "finish:" << endl;
    one->sortedInsert(insertedOne);
    one->show();
    if (one->get(2) != insertedOne) return false;
    one->clear();
    cout << "test5 pass" << endl << endl;
    return true;
}


int main(){
    if (test()){
        cout << "All tests pass!" << endl;
    }else cout << "Tests fail!";
    return 0;
}
