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
        bool pushBack(T x);
        bool pushForward(T x);
        bool sortedInsert(T x);
        T get(int x);
        void clear();

};

template<class T>
bool LinkList<T>::sortedInsert(T x){
    if(size == 0){
        pushForward(x);
        return true;
    }
    try {
        if(x < head->next->data){
            pushForward(x);
            return true;
        }
        Node<T> *temp = head->next,*keep = head->next;
        while(temp && temp->data < x){
            keep = temp;
            temp = temp->next;
        }
        Node<T> *newOne = new Node<T>();
        newOne->data = x;
        newOne->next = keep->next; 
        keep->next = newOne;
        if(keep == tail->next){
            tail->next = newOne;
            newOne->next = nullptr;
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
        if (temp == tail->next)
        {
            delete temp;
            break;
        }
        next = temp->next;
        delete temp;
        temp = next;
    }
    head->next = nullptr;
    tail->next = nullptr;
    size = 0;
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
bool LinkList<T>::pushBack(T x){
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
bool LinkList<T>::pushForward(T x){
    Node<T> *temp = new Node<T>();
    temp->data = x;
    temp->next = head->next;
    head->next = temp;
    if (!tail->next)
    {
        tail->next = temp;
    }
    
    size++;
    return true;
}


#include <algorithm>
#include<vector>
#include<random>
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
        one->pushBack(testData[i]);
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
        one->pushBack(testData[i]);
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
        one->pushBack(testData[i]);
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
    int testTimes = 1000;
    cout << "test5:" << endl;
    testData.clear();
    srand(time(nullptr));
    for (int i = 0; i < testTimes; i++)
    {
        testData.push_back(rand());
    }
    for (int i = 0; i < testTimes; i++)
    {
        if(! one->sortedInsert(testData[i])) return false;
    }
    cout << testTimes << " items are inserted" << endl;
    sort(testData.begin(),testData.end());

    for (int i = 0; i < testTimes; i++)
    {
        if (one->get(i) != testData[i])
        {
            return false;
        }
    }
    one->clear();
    cout << "test5 pass" << endl << endl;
    return true;

}


int main(){
    if (test()){
        cout << "All tests pass!" << endl;
    }else cout << "Tests fail!";
    system("pause");
    return 0;
}
