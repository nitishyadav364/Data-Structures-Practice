//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void solve(int curr,int prev,vector<int>&arr,int n,vector<int>&temp,vector<int>&ans){
        if(curr==n){
            if(temp.size()>ans.size()){
                ans=temp;
            }
            return;
        }
        if(prev==-1||arr[curr]%arr[prev]==0){
            temp.push_back(arr[curr]);
            solve(curr+1,curr,arr,n,temp,ans);
            temp.pop_back();
        }
         solve(curr+1,prev,arr,n,temp,ans);
    }
    vector<int> LargestSubset(int n, vector<int>& arr) {
    vector<int> ans;
    sort(arr.begin(), arr.end());
    vector<int> hash(n);
    vector<int> dp(n, 1);
    int max_index = 0;
    int max_ans = 1;

    for (int i = 0; i < n; i++) {
        hash[i] = i;
        for (int prev = i - 1; prev >= 0; prev--) {
            if (arr[i] % arr[prev] == 0 && dp[prev] + 1 > dp[i]) {
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        if (dp[i] > max_ans) {
            max_ans = dp[i];
            max_index = i;
        }
    }

    while (hash[max_index] != max_index) {
        ans.push_back(arr[max_index]);
        max_index = hash[max_index];
    }
    ans.push_back(arr[max_index]);  // Include the first element in the subset

    reverse(ans.begin(), ans.end());
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
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends