/*
    课本P84 Ex2.6 的解答算法： 以线性表采用数组进行存储，将数组中数据进行逆置为例

    实现方法一：采用面向过程的编程方法


*/
#include<iostream>

using namespace std;

struct seqlist
{
	int *data;
	int maxsize;
	int last;
}mylist;

//设置数据函数
void input(int size)
{
	int i;
	for(i=0;i<size;i++)
	   mylist.data[i]=i+1;
	mylist.last=size-1;
}
//输出函数
void output(void)
{
	int i;
	for(i=0;i<=mylist.last;i++)
	   cout<<mylist.data[i]<<" ";
}
//逆置函数
void reverse(void)
{
   int i,temp,n=mylist.last+1;
   
   for(i=0;i<n/2;i++)
   {  temp=mylist.data[i];
      mylist.data[i]=mylist.data[n-i-1];
	  mylist.data[n-i-1]=temp;
   }
}

void main()
{
   mylist.maxsize=100;
   mylist.data=new int[mylist.maxsize];
   
   input(10);
   cout<<"Before reverse: "<<endl;
   output();
   reverse();
   cout<<endl<<"After reverse: "<<endl;
   output();

   char x;
   cin>>x;
}
