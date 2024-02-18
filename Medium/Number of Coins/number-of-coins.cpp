//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(vector<int>&coins,int M,int V,int i){
	    if(V==0) return 0;
	    if(V<0||i>=M) return 1e7;
	    return min(1+solve(coins,M,V-coins[i],i),solve(coins,M,V,i+1));
	}
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	   // return solve(coins,M,V,0);
	    vector<vector<int>>dp(M+1,vector<int>(V+1,0));
	    for(int i=1;i<=V;i++){
	        dp[0][i]=1e7;
	    }
	    for(int i=1;i<=M;i++){
	        for(int j=1;j<=V;j++){
	            if(coins[i-1]<=j){
	            dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
	            }
	            else{
	            dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    return dp[M][V]==1e7?-1:dp[M][V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends