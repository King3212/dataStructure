/*
    课本P84 Ex2.6 的解答算法： 以线性表采用数组进行存储，将数组中数据进行逆置为例

	实现方法二：采用面向对象（类）的编程方法


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

//构造函数
seqlist::seqlist(int size)
{   if (size<=0) 
      { cout<<"空间大小申请不符合要求";exit(1);	}
	last=-1;
	maxsize=size;
	data=new int [maxsize];
	if(data==0)
	{ cout<<"空间申请不成功";exit(1);	}

}

//设置数据算法
void seqlist::input(int n)
{
	int i;
	for(i=0;i<n;i++)
	  data[i]=i+1;
	last=n-1;
}
//输出算法
void seqlist::output(void)
{
	int i;
	for(i=0;i<=last;i++)
	   cout<<data[i]<<" ";
}
//逆置算法
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
