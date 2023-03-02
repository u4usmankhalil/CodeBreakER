#include <iostream>
#include <conio.h>

using namespace std;
void heap(int arr[], int i, int n)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
 
    // if left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // if right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // if largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // recursively heap the affected sub-tree
        heap(arr, largest,n);
    }
}

void heapSort(int arr[], int n)
{
    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, i, n);
 
    // one by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);
 
        // call max heap on the reduced heap
        heap(arr, 0, i);
    }
}
 
/* function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
 

int main()
{
    int arr[] = {121, 36,3,1,0, 10012, 130, 57, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
    getch();
}
