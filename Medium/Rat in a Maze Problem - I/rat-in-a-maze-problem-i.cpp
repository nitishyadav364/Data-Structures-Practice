//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isvalid(int x,int y,int n){
        if(x<0||y<0||x>=n||y>=n){
            return false;
        }
        return true;
    }
    int xx[4]={-1,1,0,0};
    int yy[4]={0,0,-1,1};
    void solve(int i,int j,string &temp,vector<string>&ans,vector<vector<int>>&grid,int n,vector<vector<int>>&visited){
        if(i==n-1&&j==n-1){
            ans.push_back(temp);
            return;
        }
        for(int ii=0;ii<4;ii++){
            int newx=i+xx[ii];
            int newy=j+yy[ii];
            if(isvalid(newx,newy,n)&&!visited[newx][newy]&&grid[newx][newy]!=0){
                if(ii==0){ temp+="U";}
                else if(ii==1){ temp+="D";}
                else if(ii==2){ temp+="L";}
                else {temp+="R";}
                visited[newx][newy]=1;
                solve(newx,newy,temp,ans,grid,n,visited);
                visited[newx][newy]=0;
                temp.pop_back();
            }
            
        }
        
    }
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        vector<string>ans;
        if(grid[0][0]==0) return ans;
        vector<vector<int>>visited(n,vector<int>(n,0));
        visited[0][0]=1;
        string temp="";
        solve(0,0,temp,ans,grid,n,visited);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends