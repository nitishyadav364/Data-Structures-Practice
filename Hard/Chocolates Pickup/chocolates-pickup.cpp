//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int moves1[9]={1,-1,0,1,-1,0,1,-1,0};
    int moves2[9]={1,-1,0,0,0,1,-1,1,-1};
    int solve(int i,int j1,int j2,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int maxi=INT_MIN;
        for(int ii=0;ii<9;ii++){
            int newy1=j1+moves1[ii];
            int newy2=j2+moves2[ii];
            if(newy1<m&&newy2<m&&newy1>=0&&newy2>=0){
                if(j1==j2){
                    maxi=max(maxi,solve(i+1,newy1,newy2,n,m,grid,dp)+grid[i][j1]);
                }
                else{
                    maxi=max(maxi,solve(i+1,newy1,newy2,n,m,grid,dp)+grid[i][j1]+grid[i][j2]);
                }
            }
        }
        return dp[i][j1][j2]=maxi;
        
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return solve(0,0,m-1,n,m,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends