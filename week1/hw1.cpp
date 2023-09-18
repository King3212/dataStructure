#include <iostream>
using namespace std;

class linearList
{
    public:
        linearList(int length = 10){
            if(length < 0){
                cout << "length of linearList can\'t less than 0" << endl;
            }
            maxSize = length * 2;
            arr = new int[maxSize];
            this->length = length;
            for(int i = 0; i < maxSize; i++){
                arr[i] = 0;
            }
            
        };
        void show(){
            for(int i = 0; i< length; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        void sortedInsert(int x){
            int temp = x;
            for(int i = 0;i < length-1; i++){
                if(arr[i] > arr[i-1]){
                    LLsort();
                }
            }
            
            for(int i = length;i > 0; i--){
                if(x<arr[i-1]){
                    arr[i] = arr[i-1];
                }else{
                    arr[i] = x;
                }
            }

        }


    private:
        int *arr;
        int length;
        int maxSize;
        void LLsort(int start = 0,int end = -1)//Seems like Tim Sort
        {
            if(end == -1)end = length;
            else if(end - start < 0){
                cout << "end-start < 0 is not be permitted!";
                return;
            }

            // Insert Sort:
            if(end - start < 20){
                for(int i = start; i < end-1; i++){
                    if(arr[i] > arr[i+1]){
                        int temp = arr[i+1];
                        for(int j = i; j >= start; j--){
                            if(temp > arr[j]){
                                arr[j+1] = arr[j];
                            }
                            else{
                                arr[j] = temp;
                            }
                        }

                    }
                }
            }
            
            //Recursive Sort:
            else{
                int split = (start + end)/2;
                LLsort(start,split);
                LLsort(split,end);
                int *sorted = new int[end-start];
                int one = start,two = split;
                for(int i = 0; i < end-start;i++){
                    if(one == split){
                        while(two < end){
                            sorted[i] = arr[two];
                            two ++;
                            i ++;
                        }
                        break;
                    }
                    else if(two == end){
                        while (one < split){
                            sorted[i] = arr[one];
                            one++;
                            i++;
                        }
                        break;
                    }
                    else{
                        if(arr[one] < arr[two]){
                            sorted[i] = arr[one];
                            one ++;
                        }
                        else{
                            sorted[i] = arr[two];
                            two ++;
                        }
                    }
                }
                for(int i = 0;i<end-start;i++){
                    arr[start+i]= sorted[i];
                }

            }
        }



};
