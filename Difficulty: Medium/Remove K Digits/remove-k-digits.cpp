//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        
        string result = "";  // act like stack only

        for(int i=0; i<n; i++){
            while(result.length() > 0  &&  result.back() > num[i]  &&  k>0){
                result.pop_back();
                k--;
            }

            if(result.length() > 0  ||  num[i] != '0')    // skip leading 0s
                result.push_back(num[i]);
        }

        // for e.g. like 1111 or 12345
        // Our result will be same as num
        while(result.length() > 0  &&  k > 0){
            result.pop_back();
            k--;
        }

        if(result == "")
            return "0";

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends