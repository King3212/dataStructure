/*
    �α�P84 Ex2.6 �Ľ���㷨�� �����Ա����������д洢�������������ݽ�������Ϊ��

    ʵ�ַ���һ������������̵ı�̷���


*/
#include<iostream>

using namespace std;

struct seqlist
{
	int *data;
	int maxsize;
	int last;
}mylist;

//�������ݺ���
void input(int size)
{
	int i;
	for(i=0;i<size;i++)
	   mylist.data[i]=i+1;
	mylist.last=size-1;
}
//�������
void output(void)
{
	int i;
	for(i=0;i<=mylist.last;i++)
	   cout<<mylist.data[i]<<" ";
}
//���ú���
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
