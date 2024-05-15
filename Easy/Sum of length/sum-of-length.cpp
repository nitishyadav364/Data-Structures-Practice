//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int sumoflength(int arr[], int n) {
       int j=0;
       int ans=0;
       unordered_map<int,int>m;
       for(int i=0;i<n;i++)
       {
           m[arr[i]]++;
           while(m[arr[i]]>1)
           {
               m[arr[j]]--;
               j++;
           }
           int x=i-j+1;
           ans+=(x*(x+1))/2;
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.sumoflength(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends