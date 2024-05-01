//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
         int a = 1, b = 1;
        if( n == 1 || n == 2 ) return 1;
        else{
            int t;
            for( int i = 3; i <= n; i ++ ){
                t = (a + b)%1000000007;
                a = b;
                b = t;
            }
            return t;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends