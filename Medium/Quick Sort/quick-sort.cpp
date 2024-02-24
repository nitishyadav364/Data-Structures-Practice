//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
        int partition (int arr[], int low, int high)
    {
      int pivot = arr[low];
    int count = 0;
    int i = low + 1;
    while (i <= high) {
        if (arr[i] <= pivot) {
            count++;
        }
        i++;
    }
    pivot = low + count;
    swap(arr[low], arr[pivot]); // Swap pivot with its original position
    int j = pivot + 1;
    i = low;
    while (i <= pivot-1 && j <= high) {
        if (arr[i] > arr[pivot] && arr[j] <= arr[pivot]) {
            swap(arr[i], arr[j]);
            i++;
            j++;
        } else if (arr[i] <= arr[pivot]) { // Corrected this condition
            i++;
        } else {
            j++;
        }
    }
    return pivot;
    }
    void quickSort(int arr[], int low, int high)
    {
       if(low>=high) return;
       int pivot=partition(arr,low,high);
       quickSort(arr,low,pivot-1);
       quickSort(arr,pivot+1,high);
       
    }
};



//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends