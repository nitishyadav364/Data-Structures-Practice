//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int isvalid(int x,int y,vector<vector<int>>&grid){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()) return 0;
        return 1;
    }
    int xx[4]={-1,1,0,0};
    int yy[4]={0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>>que;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int count=0;
        int flag=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                pair<int,int>temp=que.front();
                que.pop();
                int x=temp.first;
                int y=temp.second;
                for(int i=0;i<4;i++){
                    int newx=x+xx[i];
                    int newy=y+yy[i];
                    if(isvalid(newx,newy,grid)&&!visited[newx][newy]&&grid[newx][newy]==1){
                        visited[newx][newy]=1;
                        que.push({newx,newy});
                        if(flag==0){
                            flag=1;
                        }
                    }
                }
            }
            if(flag==1){ 
                count++;
                flag=0;
            }
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends