//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int N, vector<int> &arr) {
        int n = N;
    vector<int> prevSmallerElement(n), nextSmallerElement(n);
    stack<int> st;
    
    // Find previous smaller element for each element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        prevSmallerElement[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    // Clear stack for next iteration
    while (!st.empty()) {
        st.pop();
    }
    
    // Find next smaller element for each element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        nextSmallerElement[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    // Calculate the sum of minimums of all subarrays
    long ans = 0;
    long mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        long left = i - prevSmallerElement[i];
        long right = nextSmallerElement[i] - i;
        ans = (ans + arr[i] * left * right) % mod;
    }
    
    return (int)ans;
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
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends