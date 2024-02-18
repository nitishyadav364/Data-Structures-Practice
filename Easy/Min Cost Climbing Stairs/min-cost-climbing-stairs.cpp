//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int solve(int i,vector<int>&cost,int n){
        if(i>=n) return 0;
        int ans=INT_MAX;
        ans=min(ans,cost[i]+min(solve(i+1,cost,n),solve(i+2,cost,n)));
        return ans;
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
    //   return min(solve(0,cost,N),solve(1,cost,N));
       int prev1=cost[1];
       int prev2=cost[0];
       int curr;
       
       for(int i=2;i<=N;i++){
           if(i==N){
               min(prev1,prev2);
           }
           else{
           curr=cost[i]+min(prev1,prev2);
           prev2=prev1;
           prev1=curr;
           }
       }
       return min(prev1,prev2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends