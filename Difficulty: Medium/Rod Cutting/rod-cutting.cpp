//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    int find(int price[], int target, int n, vector<int>& dp){
        // if(target<0)
        //     return INT_MIN;
        
        if(target == 0)
            return 0;
        
        if(dp[target]!=-1)
            return dp[target];
        
        int include = 0;
        // int exclude = 0;
        
        for(int k = 1; k<=target; k++){
            int ans = price[k-1] + find(price, target-k, n, dp);
            include = max(include, ans);
        }
        
        return dp[target] = include;
    }
  public:
    int cutRod(int price[], int n) {
        vector<int> prev(n+1, 0);
       for(int i=1;i<=n;i++){
        int include=0;
           for(int j=1;j<=i;j++){
            int ans = price[j-1] + prev[i-j];
            include= max(include, ans);
           }
           prev[i]=include;
       }
       return prev[n];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends