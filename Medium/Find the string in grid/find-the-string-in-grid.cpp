//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
      bool check(vector<vector<char>>& grid, int row, int col, string& word, vector<int>& direction) {
        int n = grid.size(), m = grid[0].size();
        int len = word.size();

        for (int i = 0; i < len; i++) {
            if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != word[i]) {
                return false;
            }
            row += direction[0];
            col += direction[1];
        }

        return true;
    }

    vector<vector<int>> searchWord(vector<vector<char>>& grid, string word) {
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (vector<int>& direction : directions) {
                    bool matched = false;
                    if(check(grid, i, j, word, direction)) {
                        matched = true;
                        ans.push_back({i, j});
                    }
                    if(matched) break;
                }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends