//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    //memoization  
    long long int mod= 1e9+7;
    long long int tdown(int n, vector<long long int>& dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n] = (tdown(n-1,dp) + tdown(n-2,dp))%mod;
    }
    
  public:
    long long int topDown(int n) {
        // code here
        vector<long long int> dp(n+1,-1);
        return tdown(n,dp);
        //tc: O(n),sc: O(n) + O(n) (stack,array(dp)).
    }
    
    // most optimized code
    long long int bottomUp(int n) {
        // code here
        // base case
       if(n<=1) return n;
       int cur, prev = 1, prev2 = 0;
       for(int i=2;i<=n;i++){
           cur = (prev + prev2)%mod;
           prev2 = prev;
           prev = cur;
       }
       return cur%mod ;
       //tc: O(n),sc: O(1).
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends