//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
  int f(int i, int j, vector<vector<int>>&dp){
        if(i==0) return 0;
        if(i==1 || j==0 || j==1) return j;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=1;k<=j;k++){
            int attempt = max(f(i, j-k, dp), f(i-1, k-1, dp)) ;
            mini=min(mini, attempt);
        }
        return dp[i][j] = mini + 1;
    }
    
    int eggDrop(int n, int m) 
    {
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return f(n, m, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends