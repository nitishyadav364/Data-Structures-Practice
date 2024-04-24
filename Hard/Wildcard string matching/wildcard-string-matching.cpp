//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{ 
    public:
    bool solve(string wild,string pattern,int i,int j,vector<vector<int>>&dp){
        if(i==wild.length()&&j==pattern.length()) return true;
        if(j==pattern.length()){
            while(i<wild.length()&&wild[i]=='*'){
                i++;
            }
            if(i==wild.length()) return true;
            return false;
        }
        if(i==wild.length()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(wild[i]==pattern[j]||wild[i]=='?'){
            return dp[i][j]= solve(wild,pattern,i+1,j+1,dp);
        }
        else{
            if(wild[i]!='*') return false;
            return dp[i][j]= solve(wild,pattern,i+1,j,dp)||solve(wild,pattern,i,j+1,dp);
        }
        
    }
    bool match(string wild, string pattern)
    {
        vector<vector<int>>dp(wild.length()+1,vector<int>(pattern.length()+1,-1));
        return solve(wild,pattern,0,0,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends