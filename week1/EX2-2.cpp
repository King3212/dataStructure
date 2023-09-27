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
        void show();
        LinkList(T x);
        LinkList();
        bool pushBack(T x);
        bool pushForward(T x);
        bool sortedInsert(T x);
        bool deleteItem(T x);
        bool removeMin();
        T get(int x);

};

template<class T>
void LinkList<T>::show()
{
    if (size == 0)
    {
        cout << "Nothing in it!" << endl;
        return;
    }
    
    Node<T> *temp = tail->next;
    while(temp != tail){
        cout << temp->data << " ";
        temp = temp-> next;
    }
    cout << temp->data << endl;
}
template<class T>
T LinkList<T>::get(int x)
{
    if (size == 0 || x < 0)
    {
        return T();
    }else{
        Node<T> *temp = tail->next;
        for (int i = 0; i < x; i++)
        {
            if (temp == tail)
            {
                return T();
            }
            temp = temp->next;
        }
        if (temp)
        {
            return temp->data;
        }
    }
    return T();
}

template<class T>
bool LinkList<T>::removeMin()
{
    if (size == 0)
    {
        return false;
    }
    
    try
    {
        T min = tail->next->data;
        Node<T> *temp = tail->next;
        for (int i = 0; i < size && temp; i++)
        {
            if (min > temp->data)
            {
                min = temp->data;
            }
            temp = temp->next;
        }
        return deleteItem(min);
        
    }
    catch(const std::exception& e)
    {
        return false;
    }
    
}

template<class T>
bool LinkList<T>::sortedInsert(T x){
    if(size == 0){
        size ++;
        return pushForward(x);
    }
    try {
        if(x < tail->next->data){
            size ++;
            return pushForward(x);
        }else if(x > tail->data){
            return pushBack(x);
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
bool LinkList<T>::pushBack(T x){
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
bool LinkList<T>::pushForward(T x){
    Node<T> *temp = new Node<T>();
    temp->data = x;
    if(size == 0){
        size ++;
        return pushBack(x);
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
    Node<T> *temp = tail,*rub;
    if(size == 0) return true;
    else if(size == 1){
        delete tail;
        size --;
        return true;
    }
    do
    {
        if (temp->data == x)
        {
            rub = temp->next;
            temp->data = rub->data;
            temp->next = rub->next;
            if (tail == rub)
            {
                tail = temp;
            }
            delete rub;
            size--;
            return true;
        }
        temp = temp->next;
    } while (temp != tail);
    return false;
}

#include <vector>
#define testLength 5

bool Test(){
    //test input
    vector<int> testData = {12,46,23,45,22};
    LinkList<int> *one = new LinkList<int>();
    for(auto i : testData){
        one->pushBack(i);
    }
    for (int i = 0; i < testLength; i++)
    {
        if(one->get(i) != testData[i]) return false;
    }
    cout << "finish insert" << endl;
    one->show();
    cout << "Remove min:" << endl;
    for (int i = 0; i < testLength; i++)
    {
        if(!one->removeMin()) return false;
        one->show();
    }
    if(!one->removeMin()) return true;
    return true;

}



int main(){
    if (Test()){
        cout << "Test pass!" << endl;
    }else cout << "Test fail!";
    return 0;
}
