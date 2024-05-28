//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		 int mod=1e9+7;
    private: int solve(string str,int index,vector<int>&dp){
        
        if(index==str.length())return 1;
        if(dp[index]!=-1)return dp[index];
        
        int include=0;
        if(str[index]!='0')
          include=solve(str,index+1,dp);
          
        int exclude=0;
        if(str[index]!='0' && index+1<str.length()){
                 string temp="";
                 temp+=str[index];
                 temp+=str[index+1];
            int a=stoi(temp);
            if(a<=26 )
              exclude=solve(str,index+2,dp);
        }
        return dp[index]=1ll*(include+exclude)%mod;
    }
    
    
    public:
        int CountWays(string str){
            // Code here
            vector<int>dp(str.length()+2,-1);
            int n=str.length();
            if(str[0]=='0')return 0;
           return  solve(str,0,dp);
        }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends