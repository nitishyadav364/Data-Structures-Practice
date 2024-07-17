//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    void subsum(int idx, int sum, vector<int>& arr, int n, vector<int>& ans){
        //base case
        if(idx == n){
            ans.push_back(sum);
            return;
        }
        
        //picking an element
        subsum(idx+1, sum+arr[idx], arr, n, ans);
        
        //do not picking an element
        subsum(idx+1, sum, arr, n, ans);
    }
    
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        subsum(0, 0, arr, N, ans);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends