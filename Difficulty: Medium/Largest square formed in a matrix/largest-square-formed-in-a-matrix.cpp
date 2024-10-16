//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int maxsquare[n][m],maxsq=0;
        for(int i=0;i<m;i++){
            if(mat[0][i]){
                maxsq=1;
                maxsquare[0][i]=1;
            }
            else maxsquare[0][i]=0;
        }
        for(int i=1;i<n;i++){
            int l=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    l++;
                    mat[i][j]+=mat[i-1][j];
                    int a=maxsquare[i-1][j],maxa=min(l,j+1);
                    if(a>=maxa) maxa=maxa;
                    else if(mat[i][j-a]>=a+1) maxa=a+1;
                    else maxa=a;
                    maxsq=max(maxsq,maxa);
                    maxsquare[i][j]=maxa;
                }
                else{ l=0; maxsquare[i][j]=0; }
                //cout<<maxsquare[i][j]<<" ";
            }
            //cout<<endl;
        }
        return maxsq;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends