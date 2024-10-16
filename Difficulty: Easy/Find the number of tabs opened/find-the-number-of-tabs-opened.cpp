//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTabs(vector<string> &arr) {
          unordered_map<string, bool> mp1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] == "END")
            {
                mp1.clear();
            }
            else
            {
                if(mp1.find(arr[i])!=mp1.end())
                {
                    mp1.erase(arr[i]);
                }
                else
                {
                    mp1[arr[i]] = true;
                }
            }
        }
        
        return mp1.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> arr;
        string str;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        int ans = ob.countTabs(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends