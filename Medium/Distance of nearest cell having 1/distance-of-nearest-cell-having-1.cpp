//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    int xx[4]={0,1,-1,0};
    int yy[4]={-1,0,0,1};
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>>que;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                ans[i][j]=0;
	                que.push({i,j});
	            }
	        }
	    }
	    int distance=1;
	    while(!que.empty()){
	        int size=que.size();
	        for(int i=0;i<size;i++){
	        pair<int,int>temp=que.front();
	        que.pop();
	        for(int x=0;x<4;x++){
	            int tempx=temp.first+xx[x];
	            int tempy=temp.second+yy[x];
	            if(tempx>=0&&tempy>=0&&tempx<n&&tempy<m&&ans[tempx][tempy]==INT_MAX){
	                ans[tempx][tempy]=distance;
	                que.push({tempx,tempy});
	            }
	        }
	       
	        }
	         distance++;
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends