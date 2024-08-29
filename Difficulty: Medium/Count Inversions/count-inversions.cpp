//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  long long ans = 0; // Global variable to store inversion count

// Function to merge two halves and count inversions
void merge(int i, int mid, int j, long long arr[]) {
    int size1 = mid - i + 1;
    int size2 = j - mid;
    long long arr1[size1], arr2[size2];

    // Copy elements to temporary arrays
    for (int x = 0; x < size1; x++) {
        arr1[x] = arr[i + x];
    }
    for (int y = 0; y < size2; y++) {
        arr2[y] = arr[mid + 1 + y];
    }

    int x = 0, y = 0, z = i;

    // Merge the two halves back into the original array
    while (x < size1 && y < size2) {
        if (arr1[x] <= arr2[y]) {
            arr[z++] = arr1[x++];
        } else {
            arr[z++] = arr2[y++];
            ans += size1 - x; // Count inversions
        }
    }

    // Copy remaining elements of arr1, if any
    while (x < size1) {
        arr[z++] = arr1[x++];
    }

    // Copy remaining elements of arr2, if any
    while (y < size2) {
        arr[z++] = arr2[y++];
    }
}

// Function to perform merge sort and count inversions
void mergesort(int i, int j, long long arr[]) {
    if (i < j) {
        int mid = i + (j - i) / 2;
        mergesort(i, mid, arr);
        mergesort(mid + 1, j, arr);
        merge(i, mid, j, arr);
    }
}

// Function to calculate inversion count using merge sort
long long int inversionCount(long long arr[], int n) {
    ans = 0; // Initialize global variable ans
    mergesort(0, n - 1, arr);
    return ans;
}

};


//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends