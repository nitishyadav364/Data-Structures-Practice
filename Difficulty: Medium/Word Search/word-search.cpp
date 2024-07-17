//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int xx[4]={1,-1,0,0};
    int yy[4]={0,0,1,-1};
    bool solve(int i,int j,vector<vector<char>>&board,string word,int x,vector<vector<int>>&visited){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()){
            return false;
        }
        if(x>=word.length()){
            return true;
        }
        if(word[x]!=board[i][j]||visited[i][j]==1){
            return false;
        }
        visited[i][j]=1;
        bool ans=false;
        for(int ii=0;ii<4;ii++){
            int tempx=i+xx[ii];
            int tempy=j+yy[ii];
            ans=ans||solve(tempx,tempy,board,word,x+1,visited);
        }
        visited[i][j]=-1;
        return ans;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),-1));
        bool ans=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                ans|=solve(i,j,board,word,0,visited);
            }
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
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends