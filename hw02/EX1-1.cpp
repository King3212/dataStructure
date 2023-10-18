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
        void show();
        LinkList(T x);
        LinkList();
        bool pushBack(T x);
        bool pushForward(T x);
        bool sortedInsert(T x);
        T get(int x);
        void clear();
        void reserve();

};

template<class T>
void LinkList<T>::show()
{
    if (size == 0)
    {
        cout << "Nothing" << endl;
        return;
    }
    
    Node<T> *temp = head->next;
    while(temp){
        cout << temp->data << " ";
        temp = temp-> next;
    }
    cout << endl;
}

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

template <class T>
void LinkList<T>::reserve()
{
    Node<T> *newHead = new Node<T>();
    Node<T> *newTail = new Node<T>();
    newTail->next = head->next;
    Node<T> *temp = head->next,*Nodenext,*Headnext;
    while (temp)
    {
        Headnext = newHead->next;
        newHead->next = temp;
        Nodenext = temp->next;
        temp->next = Headnext;
        temp = Nodenext;
    }
    delete head;
    delete tail;
    head = newHead;
    tail = newTail;
}

#include<vector>
using namespace std;

bool test(){
    vector<int> testData = {12,23,34,45,56};

    //test 1
    //test no item
    cout << "test1:" << endl;
    LinkList<int> *one = new LinkList<int>();
    for(auto i : testData){
        one->pushBack(i);
    }
    one->show();
    cout << "Items:" << endl;
    one->reserve();
    cout << "Reserve:" << endl;
    one->show();
    for (int i = 0; i < 5; i++)
    {
        if (testData[i] != one->get(4-i)) return false;
        
    }
    one->clear();
    cout << "Test1 pass" << endl << endl;
    
    //test2 no item
    cout << "test2:" << endl;
    cout << "Items:" << endl;
    one->show();
    one->reserve();
    cout << "Reserve:" << endl;
    one->show();
    one->clear();
    cout << "Test2 pass" << endl << endl;

    //test3 one item
    cout << "test3:" << endl;
    one->pushBack(1);
    cout << "Items:" << endl;
    one->show();
    one->reserve();
    cout << "Reserve:" << endl;
    one->show();
    if (one->get(0) != 1)
    {
        return false;
    }
    one->clear();
    cout << "Test3 pass" << endl << endl;

    //test 4 random test
    cout << endl << "Test2:\nRandom test:" << endl;
    srand(time(nullptr));
    int testSize = 100;
    for (int i = 0; i < testSize; i++)
    {
        testData.clear();
        for (int i = 0; i < testSize; i++)
        {
            testData.push_back(rand());
        }
        for(auto i : testData){
            one->pushForward(i);
        }
        one->reserve();
        for (int i = 0; i < testSize; i++)
        {
            if (testData[i] != one->get(i))
            {
                return false;
            }
            
        }
        
        one->clear();
        testData.clear();
    }
    cout << "Test4 pass!" << endl << endl;
    return true;
}

int main(){
    if (test()){
        cout << "All tests pass!" << endl;
    }else cout << "Tests fail!";
    system("pause");
    return 0;
}
