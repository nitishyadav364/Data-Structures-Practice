//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
         unordered_map<int,int> mp;
        for(int i = 0 ;i < nums.size() ; i++){
            mp[nums[i]%k]++;
        }
        
        for(int i = 0 ; i < k ; i++){
            if(i==0 && mp[0]%2 == 1) return false;
            if(i!= 0 && i+i == k && mp[i]%2==1) return false; 
            if(i!= 0 && mp[i]!= mp[k-i]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends