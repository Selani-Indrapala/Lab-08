#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;

   int left = 2*root+1;
   int right = 2*root +2;

   if (left<n && arr[left]>arr[largest])
        largest = left;

   if (right<n && arr[right]>arr[largest])
       largest = right;

   if (largest!=root)
   {
       int temp = arr[root];
       arr[root]=arr[largest];
       arr[largest]=temp;

       heapify(arr,n,largest);
   }

}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i= n/2 - 1;i>=0;i--){
       heapify(arr,n,i);
   }

   // extracting elements from heap one by one
   for (int i=n-1;i>=0;i--){
       int temp = arr[0];
       arr[0] = arr[i];
       arr[i] = temp;

       heapify(arr,i,0);
   }

}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int heap_arr[] = {4,6,17,50,23,7,89,32,15,10};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
