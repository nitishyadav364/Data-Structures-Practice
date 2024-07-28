//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      bool compare(string& a, string& b) {
    if (b.length() + 1 != a.length()) {
        return false;
    }
    int diff = 0;
    int i = 0, j = 0;
    while (i < a.length() && j < b.length()) {
        if (a[i] != b[j]) {
            diff++;
            i++;
            if (diff > 1) {
                return false;
            }
        } else {
            i++;
            j++;
        }
    }
    return true;
}

static bool comp(string& a, string& b) {
    return a.size() < b.size();
}
    int longestChain(int n, vector<string>& words) {
        sort(words.begin(), words.end(), comp);
    vector<int> dp(n, 1);
    int maxi = 1; // The minimum chain length is 1
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (compare(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends