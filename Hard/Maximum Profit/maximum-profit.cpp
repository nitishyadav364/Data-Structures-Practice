//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int i,int buy,int K,int N,int A[],vector<vector<vector<int>>>&dp){
        if(i==N) return 0;
        if(K<0) return -1e5;
        if(K==0&&!buy) return 0;
        if(dp[i][K][buy]!=-1){
            return dp[i][K][buy];
        }
        int ans=INT_MIN;
        if(!buy){
            ans=max(-A[i]+solve(i+1,!buy,K,N,A,dp),solve(i+1,buy,K,N,A,dp));
        }else{
             ans=max(A[i]+solve(i+1,!buy,K-1,N,A,dp),solve(i+1,buy,K,N,A,dp));
        }
        return dp[i][K][buy]=ans;
    }
    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(K+1,vector<int>(2,-1)));
        return solve(0,0,K,N,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends