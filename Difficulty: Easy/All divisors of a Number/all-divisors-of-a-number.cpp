//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        vector<int> res;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0)
                res.push_back(i);
        }
        for (auto r : res) {
            cout << r << " ";
        }
        for (int i = res.size() - 1; i >= 0; i--) {
            int r = res[i];
            if (r != (n / r))
                cout << n / r << " ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends