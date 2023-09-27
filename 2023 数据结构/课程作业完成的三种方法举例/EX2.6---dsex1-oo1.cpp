/*
    �α�P84 Ex2.6 �Ľ���㷨�� �����Ա����������д洢�������������ݽ�������Ϊ��

	ʵ�ַ�������������������ࣩ�ı�̷���


*/
#include<iostream>

using namespace std;

class seqlist
{
	int *data;
	int maxsize;
	int last;

public:
	seqlist(int size);
	void input(int size);
    void output(void);
	void reverse(void);
	~seqlist(void){delete [] data; }
};

//���캯��
seqlist::seqlist(int size)
{   if (size<=0) 
      { cout<<"�ռ��С���벻����Ҫ��";exit(1);	}
	last=-1;
	maxsize=size;
	data=new int [maxsize];
	if(data==0)
	{ cout<<"�ռ����벻�ɹ�";exit(1);	}

}

//���������㷨
void seqlist::input(int n)
{
	int i;
	for(i=0;i<n;i++)
	  data[i]=i+1;
	last=n-1;
}
//����㷨
void seqlist::output(void)
{
	int i;
	for(i=0;i<=last;i++)
	   cout<<data[i]<<" ";
}
//�����㷨
void seqlist::reverse(void)
{
   int i,temp,n=last+1;
   
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

   seqlist mylist(size);

   mylist.input(n);
   cout<<"Before reverse: "<<endl;
   mylist.output();
   mylist.reverse();
   cout<<endl<<"After reverse: "<<endl;
   mylist.output();

   char x;
   cin>>x;
}
