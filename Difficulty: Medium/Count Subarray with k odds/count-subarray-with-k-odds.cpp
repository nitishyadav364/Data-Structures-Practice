//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int n, vector<int>& nums, int k) {
        int l=0,r=0,count=0,sum=0;
        while(r<n) {
            sum += nums[r]%2;
            while(sum>k) {
                sum -= nums[l]%2;
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
    int countSubarray(int n, vector<int>& nums, int k) {
        return solve(n,nums,k) - solve(n,nums,k-1);
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends