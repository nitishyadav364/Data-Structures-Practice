//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int n, int w) 
	{ 
         int mx = 1e5;
        vector<int> dp(w + 1, mx);
        dp[0] = 0;
        for(int i = 1;i <= n;++i)
            for(int j = i;j <= w;++j)
                dp[j] = cost[i - 1] != -1 ? min(dp[j], dp[j - i] + cost[i - 1]) : dp[j];
        return dp[w] >= mx ? -1 : dp[w];
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends