//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int isvalid(int x,int y,int m,int n){
        if(x<0||y<0||x>=m||y>=n) return 0;
        return 1;
    }
    int xx[8]={-1,1,0,0,-1,1,-1,1};
    int yy[8]={0,0,+1,-1,-1,1,1,-1};
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&visited){
        visited[i][j]=1;
        for(int ii=0;ii<8;ii++){
            int newx=i+xx[ii];
            int newy=j+yy[ii];
            if(isvalid(newx,newy,grid.size(),grid[0].size())&&!visited[newx][newy]&&grid[newx][newy]=='1'){
                dfs(newx,newy,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j]&&grid[i][j]=='1'){
                    dfs(i,j,grid,visited);
                     ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends