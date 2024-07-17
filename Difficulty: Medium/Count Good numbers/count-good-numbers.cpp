//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
    long long solve(long long x, long long n) {
        if(n==0) return 1;
        if(n%2==0) {
            long long val = solve(x,n/2);
            return (val*val)%mod;
        }
        else {
            long long val = solve(x,n-1);
            return (val*x)%mod;
        }
    }
    int countGoodNumbers(long long N) {
        long long even = (N+1)/2;
        long long odd = (N/2);
        long long evAns = solve(5,even)%mod;
        long long odAns = solve(4,odd)%mod;
        return (evAns*odAns)%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;

        cout << ob.countGoodNumbers(N) << endl;
    }
}
// } Driver Code Ends