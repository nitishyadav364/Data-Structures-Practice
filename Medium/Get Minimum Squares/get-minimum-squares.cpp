//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int MinSquares(int n)
	{
	    vector<int> dp(n+1,0);
	    
	    for(int target=1;target<=n;target++){
	    int ans=n;
        for(int i=1;i*i<=target;i++){
             ans=min(ans,1+dp[target-i*i]);
        }
        dp[target]=ans;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends