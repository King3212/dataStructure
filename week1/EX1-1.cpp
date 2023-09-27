#include<iostream>
using namespace std;

#define defaultSize 5

class ArrayList{
    int *dataArr;
    int last;
    int sz;
    void check();
    void ensize();
    bool swap(int x,int y);
    void insertSort(int start, int end, bool less = true);
    void timSort(int start,int end,bool less = true);
public:
    void show();
    ArrayList(int sz = defaultSize);
    bool removeItem(int data);
    bool remove(int index);
    int search(int data);
    int pushBack(int data);
    void sort(bool less = true);
    void sortedInsert(int data, bool less = true);
    int size();
    bool removeMin();
    int get(int Index);
    void clear();
};

ArrayList::ArrayList(int sz){
    if(sz < 0) sz = 10;
    if(sz) dataArr = new int[sz];
    else dataArr = 0;
    last = -1;
    this->sz = sz;
    
}

bool ArrayList::removeItem(int data)
{
    return remove(search(data));
}

void ArrayList::sort(bool less){
    //default
    timSort(0,last+1,less);
    
      
}

bool ArrayList::remove(int index)
{
    if (index > last|| index < 0) return false;
    for (int i = index; i < last; i++)
    {
        dataArr[i] = dataArr[i+1];
    }
    last--;
    return true;
}

int ArrayList::search(int data)
{
    for (int i = 0; i <= last; i++)
    {
        if (dataArr[i] == data){
            return i;
        }
    }
    return -1;
}

void ArrayList::sortedInsert(int data, bool less){
    if (last == -1)
    {
        pushBack(data);
        return;
    }
    
    if(less){
        for (int i = 0; i < last; i++)
        {
            if (dataArr[i] > dataArr[i+1])
            {
                sort(less);
            }
        
        }
        pushBack(data);
        for (int i = last-1; i >= 0; i--)
        {
            if (dataArr[i] > dataArr[i+1])
            {
                swap(i,i+1);
            }
            
        }
    }
    else{
        for (int i = 0; i < last; i++)
        {
            if (dataArr[i] < dataArr[i+1])
            {
                sort(less);
            }
        
        }
        pushBack(data);
        for (int i = last-1; i >= 0; i--)
        {
            if (dataArr[i] < dataArr[i+1])
            {
                swap(i,i+1);
            }
            
        }
    }
    
}

int ArrayList::size()
{
    return sz;
}

int ArrayList::pushBack(int data){
    check();
    dataArr[last+1] = data;
    last ++;
    return last;
}

void ArrayList::check(){
    if (last+1 == sz)
    {
        ensize();
    }
    
}

void ArrayList::ensize(){
    if (sz == 0)
    {
        sz = 10;
        dataArr = new int[sz];
    }else{
        int *temp = new int[sz*2];
        for (int i = 0; i < sz; i++)
        {
            temp[i] = dataArr[i];
        }
        delete dataArr;
        dataArr = temp;
        sz *= 2;
    }
    
}

bool ArrayList::swap(int x, int y)
{
    if(x < 0 || x > last || y < 0 || y > last) return false;
    dataArr[x] += dataArr[y];
    dataArr[y] = dataArr[x]-dataArr[y];
    dataArr[x] = dataArr[x]-dataArr[y];
    return true;
}

void ArrayList::insertSort(int start, int end, bool less)
{
    int temp,i,j;
    for(i = start+1; i < end; i++){
        temp = dataArr[i];
        for(j = i; j > start&& temp < dataArr[j-1]; j--){
            dataArr[j] = dataArr[j-1];
        }
        dataArr[j] = temp;
    }
}

void ArrayList::timSort(int start, int end, bool less)
{
    if (end - start <= 20)
    {
        insertSort(start,end,less);
    }
    else{
        int mid = (end + start)/2;
        timSort(start,mid,less);
        timSort(mid,end,less);
        int *Arr = new int[end-start];
        int j = mid,i = 0;
        for (int k = 0; k < end - start; k++)
        {
            if (j == end)
            {
                Arr[k] = dataArr[i];
                i++;   
            }else if(i == mid){
                Arr[k] = dataArr[j];
                j++;  
            }else{
                if (less){
                    if (dataArr[i] < dataArr[j]){
                        Arr[k] = dataArr[i];
                        i++;
                    }else{
                        Arr[k] = dataArr[j];
                        i++;
                    }
                }
                else{
                    if (dataArr[i] > dataArr[j]){
                        Arr[k] = dataArr[i];
                        i++;
                    }else{
                        Arr[k] = dataArr[j];
                        i++;
                    }
                }
            }
            
        }

    }
    
}

bool ArrayList::removeMin()
{
    if (last == -1)
    {
        return false;
    }
    int minIndex = 0;
    for (int i = 0; i <= last; i++)
    {
        if (dataArr[i] < dataArr[minIndex])
        {
            minIndex = i;
        }
        
    }
    remove(minIndex);
    
    return true;
}

void ArrayList::show()
{
        if (last == -1)
        {
            cout << "Nothing in ArrayList!" << endl;
            return;
        }
        
        for (int i = 0; i <= last; i++)
        {
            cout << dataArr[i] << " ";
        }
        cout << endl;
        
    }

int ArrayList::get(int Index)
{
    if(Index < 0){
        return -1;
    }
    else if(Index > last){
        return -2;
    }
    else return dataArr[Index];
}
void ArrayList::clear()
{
    last = -1;
    delete dataArr;
    dataArr = new int[sz];
}

#include <vector>


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
    ArrayList *one = new ArrayList(0);
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
    //ArrayList is full, insert
    cout << "test5:" << endl;
    for (int i = 0; i < 5; i++)
    {
        one->pushBack(testData[i]);
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


