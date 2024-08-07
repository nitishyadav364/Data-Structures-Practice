//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>&  nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2) return MedianOfArrays(nums2, nums1); // Ensure nums1 is the smaller array

    int low = 0, high = n1;
    int total = n1 + n2;
    while (low <= high) {
        int mid1 = low + (high - low) / 2;
        int mid2 = (total + 1) / 2 - mid1;

        int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

        if (l1 <= r2 && l2 <= r1) {
            if (total % 2 == 0) {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else {
                return max(l1, l2);
            }
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return -1.0;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends