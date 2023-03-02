#include<iostream>
#include<conio.h>
#include<string.h>
#define size 1000
using namespace std;
class bubble{
	int a[size];
	public:
		void input(int);
		void print(int);
		void swap(int *,int*);
		void bubbl(int);
};
void bubble::input(int s)
{
	for(int i=0;i<s;i++)
	{
		cout<<"Enter a number:";cin>>a[i];
	}
}
void bubble::print(int s)
{
	for(int i=0;i<s;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void bubble::swap(int *a,int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
void bubble::bubbl(int s)
{
	for(int i=0;i<s;i++)
	{
		for(int j=0;j<s-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j+1],&a[j]);
			}
		}
	}
}
main()
{
	bubble b1;int n;
	cout<<"Enter array size:";cin>>n;
	b1.input(n);
	cout<<"Before\n";
	b1.print(n);
	b1.bubbl(n);
	cout<<"After\n";
	b1.print(n);
	getch();
}

