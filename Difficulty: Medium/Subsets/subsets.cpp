//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solve(int i,vector<int>&temp,vector<vector<int>>&ans,vector<int>&a){
        if(i==a.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(a[i]);
        solve(i+1,temp,ans,a);
        temp.pop_back();
        solve(i+1,temp,ans,a);
        
    }
    vector<vector<int> > subsets(vector<int>& a) {
        vector<vector<int>>ans;
        vector<int>temp={};
        solve(0,temp,ans,a);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n;

        vector<int> array;
        for (int i = 0; i < n; i++) {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int> > res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends