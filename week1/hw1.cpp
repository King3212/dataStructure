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
            notNull = 0;
            
        };
        void show(){
            for(int i = 0; i< notNull; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        
        void Insert(int x){
            if(notNull >= length){
                length++;
            };
            arr[notNull] = x;
            notNull++;
            check();
        }
        void DeleteMin(){
            int min = arr[0],index = 0;
            for(int i = 0; i < notNull;i++){
                if(min > arr[i]){
                    min = arr[i];
                    index = i;
                }
            }
            for(int i = index; i < notNull;i++){
                arr[i] = arr[i+1];
            }

            if(notNull == length){
                length--;
            }
            notNull --;
        }

        void sortedInsert(int x){
            int temp = x;
            for(int i = 0;i < notNull-1; i++){
                if(arr[i] > arr[i+1]){
                    LLsort();
                }
            }
            
            for(int i = notNull;i > 0; i--){
                if(x < arr[i-1]){
                    arr[i] = arr[i-1];
                    if(i == 1) arr[0] = x;
                }
                else{
                    arr[i] = x;
                    break;
                }
            }
            if(notNull == length) length ++;
            notNull ++;
            check();
        }


    private:
        int notNull;
        int *arr;
        int length;
        int maxSize;
        void LLsort(int start = 0,int end = -1)//Seems like Tim Sort
        {
            if(end == -1)end = notNull;
            else if(end - start < 0){
                cout << "end-start < 0 is not be permitted!";
                return;
            }

            // Insert Sort:
            if(end - start < 20){
                int temp,i,j;
                for(i = start+1; i < end; i++){
                    temp = arr[i];
                    for(j = i; j > start&& temp < arr[j-1]; j--){
                        arr[j] = arr[j-1];
                    }
                    arr[j] = temp;
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

        void check(){
            if(length == maxSize)
            {
                extendList();
            }
        }

        void extendList(){
            int *newArr = new int[maxSize*2];
            for(int i = 0; i < length; i++){
                newArr[i] = arr[i];
            }
            delete arr;
            arr = newArr;
        }


};


int main(){
    linearList oneList = linearList();
    int x = 0;
    while(true){
        cin >> x;
        if(x == -1){
            break;
        }

        oneList.Insert(x);
    }
    oneList.show();
    cout << "1-(1): insert"<<endl;
    cin >> x;
    oneList.sortedInsert(x);
    cout << "inserted"<<endl;
    oneList.show();
    cout << "2-(1): delete min"<<endl;
    oneList.DeleteMin();
    cout << "deleted" << endl;
    oneList.show();
    return 0;
}


    
