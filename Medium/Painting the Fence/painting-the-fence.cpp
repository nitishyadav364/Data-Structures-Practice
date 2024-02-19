//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
         long mod = 1000000007;
        long Same = 0;
        long Diff = k;
        
        for(int i=2;i<=n;i++){
            long temp = Same;
            Same = Diff;
            Diff = ((temp + Diff)%mod * (k-1)%mod)%mod;
        }
        
        return (Same+Diff)%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends