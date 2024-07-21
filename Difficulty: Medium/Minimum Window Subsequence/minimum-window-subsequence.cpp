//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int i=0, j=0, k=0;
        string ans;
        int sz = 1e9;
        for(i=0,j=0; i<n && k<m; ){
            if(s[i]==t[k]){
                k++;
            }
            
            // fixing end point
            if(k==m){
                j=i;
                k=m-1;
                
                //minimising our starting point
                while(k>=0 && j>=0){
                    if(s[j]==t[k]) k--;
                    j--;
                }
                j++;
                
                // now this can be our substring i.e. s[j..i]
                if(sz>(i-j+1)){
                    sz = i-j+1;
                    ans = s.substr(j,sz);
                }
                i=j;
                k=0;
            }
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends