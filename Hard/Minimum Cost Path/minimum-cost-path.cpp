//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        
        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};
    
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int r = it.second.first;
            int c = it.second.second;
            int d = it.first;
            
            if(r==n-1 && c==m-1) return d;
            
            for(int i=0;i<4;i++){
                int nrow = r+dr[i];
                int ncol = c+dc[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int exdis = grid[nrow][ncol]+d;
                    if(exdis<dist[nrow][ncol]){
                        dist[nrow][ncol] = exdis;
                        pq.push({exdis,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends