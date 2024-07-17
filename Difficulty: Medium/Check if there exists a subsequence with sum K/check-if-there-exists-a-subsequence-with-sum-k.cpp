//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        
        // space optimised
        vector<int> curr(k+1, false);
        vector<int> next(k+1, false);
        next[0] = true;
        
        for(int index = n-1; index >= 0; index--){
            for(int target = 1; target <= k; target++){
                
                curr[0] = true;
            
                bool include = false;
                if(target - arr[index] >= 0)
                    include = next[target - arr[index]];
                
                bool exclude = next[target];
                
                curr[target] = include or exclude;
            }
            next = curr;
        }
        return next[k];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends