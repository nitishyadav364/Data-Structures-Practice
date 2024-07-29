//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
 
class Solution {
  public:
    int findMatching(string text, string pat) {
       int t = text.size();
        int p = pat.size();
        for(int i = 0;i<t;i++){
            if(text[i]==pat[0]){
                int j = 1;
                int k = i+1;
                while(j<p && k<t){
                    if(pat[j]!=text[k]){
                        break;
                    }
                    k++;
                    j++;
                }
                if(j>=pat.size()) return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends