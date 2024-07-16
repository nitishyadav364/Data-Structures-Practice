//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& nums) {
        stack<int>st;
        if(N==1){
            return {-1};
        }
        vector<int>ans(nums.size(),-1);
        for(int i=nums.size()-2;i>=0;i--){
              if(st.empty()){
                st.push(nums[i]);
              }
              else{
                while(!st.empty()&&st.top()<=nums[i]){
                      st.pop();
                }
                st.push(nums[i]);
              }
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums[i]){
                      st.pop();
            }
                if(!st.empty()&&st.top()>nums[i]){
                    ans[i]=st.top();
                }
                else{
                    ans[i]=-1;
                }
                st.push(nums[i]);
              }
        
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
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends