#include<iostream>
using namespace std;

#define defaultSize 10

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
    if(less){
        for (int i = 0; i < last; i++)
        {
            if (dataArr[i] > dataArr[i+1])
            {
                sort(less);
            }
        
        }
        pushBack(data);
        for (int i = less-1; i > 0; i--)
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
        for (int i = less-1; i > 0; i--)
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

#include <vector>
#define testLength 5



bool Test(){
    //test input
    bool testPass = true;
    vector<int> testData = {12,46,23,45,22};
    ArrayList *one = new ArrayList();
    for(auto i : testData){
        one->pushBack(i);
    }
    for (int i = 0; i < testLength; i++)
    {
        if(one->get(i) != testData[i]) testPass = false;
    }
    cout << "finish insert" << endl;
    one->show();
    cout << "Remove min:" << endl;
    for (int i = 0; i < testLength; i++)
    {
        if(!one->removeMin()) testPass = false;
        one->show();
    }
    if(one->removeMin()) testPass = false;
    return testPass;
}



int main(){
    if (Test()){
        cout << "Test pass!" << endl;
    }else cout << "Test fail!";
    return 0;
}


