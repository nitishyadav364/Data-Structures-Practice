//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
       vector<int>prev=points[0];
       vector<int>curr=points[0];
       for(int i=1;i<n;i++){
           curr[0]=max(prev[1],prev[2])+points[i][0];
           curr[1]=max(prev[0],prev[2])+points[i][1];
           curr[2]=max(prev[1],prev[0])+points[i][2];
           prev=curr;
       }
       return max(prev[0],max(prev[1],prev[2]));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends