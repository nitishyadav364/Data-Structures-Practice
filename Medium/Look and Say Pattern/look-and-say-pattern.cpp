//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  void solve(string &s, int j, int n)
{
    if (j == n)
        return;
    int len = s.size();
    string temp;
    for (int i = 0; i < len; i++)
    {
        unordered_map<char, int> mp;
        char saved = s[i];
        mp[saved]++;
        while (i + 1 < len && s[i + 1] == saved)
        {
            i++;
            mp[s[i]]++;
        }
        for (auto it : mp)
        {
            temp += to_string(it.second) + it.first;
        }
    }
    s=temp;
    // cout<<s<<endl;
    solve(s, j + 1, n);
}
string lookandsay(int n)
{
    string ans = "1";
    solve(ans, 1, n);
    return ans;
}  
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends