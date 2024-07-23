//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int xx[4]={1,0,-1,0};
    int yy[4]={0,1,0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int first_color = image[sr][sc];
    
    // Early exit if the color is already the same as newColor
    if (first_color == newColor) {
        return image;
    }

    queue<pair<int, int>> que;
    que.push({sr, sc});
    image[sr][sc] = newColor;

    while (!que.empty()) {
        auto temp = que.front();
        que.pop();
        int x = temp.first;
        int y = temp.second;

        for (int i = 0; i < 4; i++) {
            int new_x = x + xx[i];
            int new_y = y + yy[i];

            if (new_x >= 0 && new_x < image.size() && new_y >= 0 && new_y < image[0].size() && image[new_x][new_y] == first_color) {
                image[new_x][new_y] = newColor; // Update before adding to queue
                que.push({new_x, new_y});
            }
        }
    }

    return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends