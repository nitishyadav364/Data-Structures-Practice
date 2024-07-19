//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
       int lastseen[3]={-1,-1,-1};
        int cnt=0;
        for(int i=0;i<s.length();i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1&&lastseen[1]!=-1&&lastseen[2]!=-1){
                cnt+=1+min(lastseen[0],min(lastseen[1],lastseen[2]));
            } 
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends