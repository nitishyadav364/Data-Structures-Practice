//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        
vector<long long int> dp(N+1, 0);
dp[0] = dp[1] = 1;
int l, r;
for(int i = 2; i <= N; i++){
    l = 0;
    r = i-1;
    while(l <= r){
        if(l < r){
            // {0, ROOT, N-1} + {N-1, ROOT, 0} => 2*{0, ROOT, N-1} 
            dp[i] = (dp[i] + (2*dp[l]*dp[r])%(1000000007))%(1000000007);
        }
        else{
            // if N is odd i.e. {2, ROOT, 2} 
            dp[i] = (dp[i] + (dp[l]*dp[r])%(1000000007))%(1000000007);
        }
        l++;
        r--;
    }
}
return dp[N];
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends