// C++ program for implementation of
// selection sort
#include <iostream>
#include <conio.h>
#define max 10
using namespace std;
class selection{
	int arr[max];
	public:
		void swap(int*,int*);
		void selectionSort(int n);
		void print(int);
		void input(int);
};
void selection::swap(int *a, int *b)
{ 
	 int t = *a;
 	 *a = *b;
 	 *b = t;
}

void selection::selectionSort(int n)
{
	int i, j, min;
	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		{
		if (arr[j] < arr[min])
			min = j;
		}
		if (min!=i)
		{
//		swap(&arr[min], &arr[i]);
		int temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
		}
	}
}
void selection::print(int size)
{
	int i;
	for (i=0; i < size; i++)
	{
	cout << arr[i] << " ";
	}
	cout << endl;
}
void selection::input(int s)
{
	for(int i=0;i<s;i++)
	{
		cout<<"Enter number:";cin>>arr[i];
	}
}
int main()
{
	int arr[max],n;selection s1;
	cout<<"Enter array Size:";cin>>n;
	s1.input(n);
	cout << "Array Before Sorting is: \n";
	s1.print(n);
	s1.selectionSort(n);
	cout << "Array after Sorting is: \n";
	s1.print(n);
	getch();
}
