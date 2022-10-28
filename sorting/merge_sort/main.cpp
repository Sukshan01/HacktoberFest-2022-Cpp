// C++ program to implement Merge Sort, iteratevly
#include <iostream>
#include<array>
using namespace std;


void merge(int *arr, int l, int m, int r) 
{
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = arr[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = arr[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) 
   {
      if(larr[i] <= rarr[j]) {
         arr[k] = larr[i];
         i++;
      }else{
         arr[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) 
   {       //extra element in left array
      arr[k] = larr[i];
      i++; k++;
   }
   while(j<nr) 
   {     //extra element in right array
      arr[k] = rarr[j];
      j++; k++;
   }
}


void mergeSort(int arr[],int begin,int end)
{  
         // divide the array into blocks of size `m`
    for (int m = 1; m <= end - begin; m = 2*m)
    {
        // for m = 1, i = 0, 2, 4, 6, 8…
        // for m = 2, i = 0, 4, 8…
        // for m = 4, i = 0, 8…
        // …
        for (int i = begin; i < end; i += 2*m)
        {
            int from = i;
            int mid = i + m - 1;
            int to = min(i + 2*m - 1, end);
 
            merge(arr, from, mid, to);
        }
    }
}

void printArray(int arr[], int n)  // function to print elements of array
{
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver Code
int main()
{   
    int size;
    cin>>size; //size of array
    int arr[size];
    
    for(int i=0;i<size;i++)
    {
       cin>>arr[i]; // elemnents in the array
    }
   
   mergeSort(arr,0,size-1);
   
   printArray(arr, size);
   return 0;
}