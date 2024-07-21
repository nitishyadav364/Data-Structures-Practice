//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long count(int n,vector<int>&arr,long k ){
        long ans=0;
        long sum=0;
        for(int l=0, r=0; r<n;r++){
            sum+=arr[r];
            while(sum>k){
                sum-=arr[l];
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    long countSubarray(int N,vector<int>&A,long L,long R) {
        // code here
        long ans1=count(N,A,R);
        long ans2=count(N,A,L-1);
        return ans1-ans2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends