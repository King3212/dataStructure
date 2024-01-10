/*
    课本P84 Ex2.6 的解答算法： 以线性表采用数组进行存储，将数组中数据进行逆置为例

	实现方法三：采用面向对象（类模板）的编程方法


*/
#include<iostream>

using namespace std;

template <class T>
class seqlist
{
	T *data;
	int maxsize;
	int last;

public:
	seqlist(int size);
	void input(int size);
    void output(void);
	void reverse(void);
	~seqlist(void){delete [] data; }
};

//构造函数
template <class T>
seqlist<T>::seqlist(int size)
{   if (size<=0) 
      { cout<<"空间大小申请不符合要求";exit(1);	}
	last=-1;
	maxsize=size;
	data=new T [maxsize];
	if(data==0)
	{ cout<<"空间申请不成功";exit(1);	}

}

//设置数据算法
template <class T>
void seqlist<T>::input(int n)
{
	int i;
	for(i=0;i<n;i++)
	  data[i]=i+1;
	last=n-1;
}

//输出算法
template <class T>
void seqlist<T>::output(void)
{
	int i;
	for(i=0;i<=last;i++)
	   cout<<data[i]<<" ";
}

//逆置算法
template <class T>
void seqlist<T>::reverse(void)
{
   int i,n=last+1;
   T temp;

   for(i=0;i<n/2;i++)
   {  temp=data[i];
      data[i]=data[n-i-1];
	  data[n-i-1]=temp;
   }
}

void main()
{
   int size=100;
   int n=10;

   seqlist<int> mylist(size);

   mylist.input(n);
   cout<<"Before reverse: "<<endl;
   mylist.output();
   mylist.reverse();
   cout<<endl<<"After reverse: "<<endl;
   mylist.output();

   char x;
   cin>>x;
}
