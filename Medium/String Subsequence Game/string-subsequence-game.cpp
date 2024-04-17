//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    
    bool isConso(char ch){
        if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u'){
            return true;
        }
        return false;
    }
  
    void solve(int index, string res, set<string> &ans, string str){
        
        int n = str.size();
        
        if(index == n){
            if(res.size() != 0 && isVowel(res[0]) && isConso(res[res.size() - 1])){
                ans.insert(res);
            }
            return;
        }
        
        // not pick
        solve(index+1, res, ans, str);
        
        //pick
        res.push_back(str[index]);
        solve(index+1, res, ans, str);
    }
  
    set<string> allPossibleSubsequences(string str) {
        
        set<string> ans;
        
        int index = 0;
        string res = "";
        solve(index, res, ans, str);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends