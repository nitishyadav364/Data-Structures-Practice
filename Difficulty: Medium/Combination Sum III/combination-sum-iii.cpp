//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(int i,int k,int n,vector<int>&temp,vector<vector<int>>&ans){
            if (k < 0 || n < 0) {
        return;
    }
    if (k == 0) {
        if (n == 0) {
            ans.push_back(temp); // Add valid combination to the answer
        }
        return; // No need to proceed further
    }
    if (i == 10) {
        return; // End of range, stop further processing
    }

    // Recursive case 1: Include the current number
    if (i <= n) {
        temp.push_back(i);
        solve(i + 1, k - 1, n - i, temp, ans);
        temp.pop_back();
    }

    // Recursive case 2: Exclude the current number
    solve(i + 1, k, n, temp, ans);
}
    vector<vector<int>> combinationSum(int k, int n) {
       vector<int> temp;
    vector<vector<int>> ans;
    solve(1, k, n, temp, ans); // Start recursion with 1
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends