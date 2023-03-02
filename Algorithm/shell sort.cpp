#include<iostream> 
#include<conio.h>
#define max 1000 
using namespace std; 
class Shell{
	int a[max];
	public:
		void Sort(int);
		void display(int);
		void Input(int n);
};
void Shell::Sort(int n)
{
	int temp,gap,j,i;
	for(gap=n/2;gap>0;gap /= 2)
	{
		for(j = gap;j<n;j+=1)
		{
			temp = a[j];
			for(i=j;i>=gap && a[i-gap]>temp;i=i-gap)
			{
				a[i] = a[i-gap];
			}
			a[i] = temp;
		}
	}
	cout<<endl;
}
void Shell::Input(int s)
{
	for(int i=0;i<s;i++)
	{
		cout<<"Enter a number:";
		cin>>a[i];
	}
}
void Shell::display(int n)
{
	int i;
	for(i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
	
}
int main() 
{ 
	Shell s1;
	int n;
	cout<<"Enter the size of the array: "<<endl;
	cin>>n;
	cout<<"Enter "<<n<<" integers in any order"<<endl;
	s1.Input(n);
	cout<<endl<<"Before Sorting: "<<endl;
	s1.display(n);		
	cout<<endl<<endl<<"SHELL SORT "<<endl;
	s1.Sort(n); 
	cout<<endl<<"After Sorting: "<<endl;
	s1.display(n);
	getch();
}
