//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
          int isValid(string s) {
        vector<string> nums;
        string num = "";
        for (char c : s) {
            if (c == '.') {
                nums.push_back(num);
                num = "";
            } else {
                num += c;
            }
        }
        nums.push_back(num);
        if (nums.size() != 4) return 0;
        for (string x : nums) {
            if (x.size() > 3 || x.size() == 0 || (x.size() > 1 && x[0] == '0')) return 0;
            int val = 0;
            for (char c : x) {
                if (!isdigit(c)) return 0;
                val = val * 10 + (c - '0');
            }
            if (val < 0 || val > 255) return 0;
        }
        return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends