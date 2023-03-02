// C++ program for implementation of
// Count sort
#include <iostream>
#include <conio.h>
#define max 1000
using namespace std;
class count{
	int array[max];
	public:
		void countSort(int);
		void print(int);
		void input(int);
		int	getmax(int);
};
int count::getmax(int s)
{
	int mx=array[0];
	for(int i=0;i<s;i++)
	{
		 if(array[i] > mx)  
         mx = array[i];  
	}
	return mx;
}
void count::countSort(int size) {
  int output[size];
  int mx=getmax(size);//mx means the maximum element
  int count[mx];
  for (int i = 0; i <= mx; ++i) {
    count[i] = 0;
  }
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }
  for (int i = 1; i <= mx; i++) {
    count[i] += count[i - 1];
  }
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] -1] = array[i];
    count[array[i]]--;// decrease count for same numbers  
  }
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}
void count::print(int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
void count::input(int s)
{
	for(int i=0;i<s;i++)
	{
		cout<<"Enter a number:";cin>>array[i];
	}
}
int main() {
  int i,array[max],s;count c1;
 cout<<"Enter Array Size:";cin>>s;
  c1.input(s);
  cout<<"Before Sorting\n";
  c1.print(s);
  c1.countSort(s);  
  cout<<"After Sorting\n";
  c1.print(s);
  getch();
}
