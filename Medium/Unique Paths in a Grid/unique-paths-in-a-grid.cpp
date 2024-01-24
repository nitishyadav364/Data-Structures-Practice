//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int x=1e9+7;
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<int>prev(m,0);
        vector<int>curr(m,0);
        if(grid[0][0]==0) return 0;
        int flag=0;
        for(int i=0;i<m;i++){
            if(grid[0][i]==0){
                flag=1;
            }
            if(flag) prev[i]=0;
            else{
                prev[i]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) curr[j]=0;
                else if(j==0){
                    curr[j]=prev[j]%x;
                }
                else{
                    curr[j]=(curr[j-1]%x+prev[j]%x)%x;
                }
                
            }
            prev=curr;
        }
        return prev[m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends