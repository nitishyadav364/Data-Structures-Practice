//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	   vector<int>dp(n,1);
	    vector<int>total(n,0);
	    int maxi = 1;
	    for(int i = 0; i < n; i++)
	    {
	        total[i] = arr[i];
	        for(int prev = 0;prev<i;prev++)
	        {
	            if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i] && total[prev] + arr[i] > total[i]){
	                dp[i] = 1 + dp[prev];
	                total[i] = arr[i] + total[prev];
	            }
	        }
	        maxi = max(maxi,total[i]);
	    }
	    
	    return maxi;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends