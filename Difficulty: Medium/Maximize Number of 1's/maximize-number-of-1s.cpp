//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int nums[], int n, int k) {
        int i = 0;
    int j = 0;
    int max_len = 0;

    while (j < n) {
        // If we encounter a 0, decrement k
        if (nums[j] == 0) {
            k--;
        }

        // If k is less than 0, it means we have more than k zeros in the window
        // Adjust the start of the window until k is non-negative
        while (k < 0) {
            if (nums[i] == 0) {
                k++;
            }
            i++;
        }

        // Calculate the maximum length of the window
        max_len = max(max_len, j - i + 1);
        j++;
    }

    return max_len;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends