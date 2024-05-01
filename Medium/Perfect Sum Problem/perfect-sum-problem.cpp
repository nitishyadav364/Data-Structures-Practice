//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int x=1e9+7;
	int solve(int i,int n,int arr[],int sum,vector<vector<int>>&dp){
	  
	    if(sum==0){
	        int x=0;
	        int temp=i;
	        while(temp<n){
	            if(arr[temp]==0){
	                x++;
	            }
	            temp++;
	        }
	        return pow(2,x);
	    }
	      if(i==n) return 0;
	      if(dp[i][sum]!=-1){
	          return dp[i][sum];
	      }
	    if(arr[i]<=sum){
	    return dp[i][sum]=(solve(i+1,n,arr,sum-arr[i],dp)%x+solve(i+1,n,arr,sum,dp)%x)%x;
	    }
	    return dp[i][sum]=solve(i+1,n,arr,sum,dp)%x;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
       return solve(0,n,arr,sum,dp)%x;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends