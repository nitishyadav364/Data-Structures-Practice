//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPossible(int s1, int s2, int n, int mid)
    {
        if((mid/s1)+(mid/s2) >= n)
            return true;
        return false;
    }
    int minTime(int s1, int s2, int n){
        int start = 0;
        int end = min(s1*n,s2*n);
        int ans = 0;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isPossible(s1, s2, n, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S1, S2, N;
        cin>>S1>>S2>>N;
        
        Solution ob;
        cout<<ob.minTime(S1, S2, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends