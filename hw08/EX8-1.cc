#include<iostream>
using namespace std;

void quickSort(int array[],int size){
    if (size <= 1) return;
    int left = 1;
    int right = size-1;
    while (left <= right)
    {
        if (array[left] > array[0])
        {
            while (left<=right)
            {
                if (array[right] < array[0])
                {
                    swap(array[left], array[right]);
                    break;
                }
                right-=1;
                
            }
            
        }else{
            left += 1;
        }

        
    }
    swap(array[0], array[right]);
    quickSort(array+left,size-left);
    quickSort(array,right);
}

int main(){
    int *array, size;
    while (true)
    {
        cout << "待排序的元素个数，以输入 -1   来结束整个程序的运行。" << endl;
        cin >> size;
        if (size < 0) break;
        array = new int[size];
        cout << "输入待排序的每一个元素（整数）" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }
        cout << endl << "排序前的元素序列" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }

        quickSort(array,size);

        cout << endl << "排序前的元素序列" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        delete[] array;
        cout << endl << endl;
    }
    
}
