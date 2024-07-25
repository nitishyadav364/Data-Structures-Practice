//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int> , int>> q;
        q.push({source , 0});
        
        vector<vector<int>> vis(n , vector<int>(m,0));
        vis[source.first][source.second] = 1;
        
        int targetx = destination.first;
        int targety = destination.second;
        int ans = 1e9;
        
        while(!q.empty()){
            auto it = q.front();
            int x = it.first.first;
            int y = it.first.second;
            int d = it.second;
            
            q.pop();
            
            if(x == targetx && y == targety){
                ans = min(ans , d);
            }
            
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};
            
            for(int i = 0; i<4 ; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 1 ){
                    q.push({{newx,newy} , d + 1});
                    grid[newx][newy] = 0;
                }
            }
        }
        
        
        if(ans == 1e9) return -1;
        return ans;
    }
};



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends