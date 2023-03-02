// Quick sort in C++
#include <iostream>
#include <conio.h>
#define max 1000
using namespace std;
class Quick{
	int array[max];
	public:
		void swap(int *,int *);
		int partition(int,int);
		void quickSort(int,int);
		void print(int);
		void input(int);
};
void Quick::swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
void Quick::print(int size) {
  int i;
  for (i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

// function to rearrange array (find the partition point)
int Quick::partition(int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = array[high];
  int temp;
  // pointer for greater element
  int i =low - 1;
  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {     
     // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++; 	      
     // swap element at i with element at j
      swap(&array[i], &array[j]);
//		temp=array[i];
//		array[i]=array[j];
//		array[j]=temp;
    }
  }
  i++;//for getting an empty place for storing my pivot element
  // swap pivot with the greater element at i
  swap(&array[i], &array[high]);
//	temp=array[i];
//	array[i]=array[high];//here high means we are getting place for our pivot element
//	array[high]=temp;
  
  // return the partition point
  return i;
}

void Quick::quickSort(int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(low, high);

    // recursive call on the left of pivot
    quickSort(low, pi - 1);

    // recursive call on the right of pivot
    quickSort(pi + 1, high);
  }
}
void Quick::input(int size)
{
	int i;
	cout<<"\t\t\t\tEnter "<<size<<" numbers"<<endl;
	for(i=0;i<size;i++)
	{
		cout<<"Enter a number:";
		cin>>array[i];
	}
}
int main() {
	Quick q1;
	int s;
	cout<<"Enter array size:";cin>>s;
	q1.input(s);
	cout<<"Unsorted Array is:"<<endl;
	q1.print(s);
	q1.quickSort(0, s - 1); 
	cout << "Sorted array in ascending order: \n";
	q1.print(s);
	getch();
}
