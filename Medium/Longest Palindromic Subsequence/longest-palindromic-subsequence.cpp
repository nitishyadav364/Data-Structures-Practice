//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
         int n=A.length();
        string a1=A;
        reverse(A.begin(),A.end());
         vector<vector<int>> vec(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(A[i-1]==a1[j-1]){
                    vec[i][j]=1+vec[i-1][j-1];
                }
                else{
                    vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
                }
            }
        }
        return vec[n][n];
    }
};


//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends