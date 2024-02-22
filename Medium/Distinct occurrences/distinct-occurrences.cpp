//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int x=1e9+7;
    int solve(int i,int j,string s,string t){
        if(j==t.length()) return 1;
        if(i==s.length()) return 0;
        long long ans=0;
        if(s[i]==t[j]){
            ans=(solve(i+1,j+1,s,t)%x+solve(i+1,j,s,t)%x)%x;
        }
        else{
           ans=solve(i+1,j,s,t)%x;
        }
        return ans%x;
    }
    int subsequenceCount(string s, string t)
    {
      
      vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,0));
      for(int i=0;i<s.length();i++){
          dp[i][0]=1;
      }
      
      for(int i=1;i<=s.length();i++){
          for(int j=1;j<=t.length();j++){
              long long ans=0;
              if(s[i-1]==t[j-1]){
                 dp[i][j]=(dp[i-1][j-1]%x+dp[i-1][j]%x)%x;
               } 
               else{
                  dp[i][j]=dp[i-1][j]%x;
                }
          }
      }
      return dp[s.length()][t.length()]%x;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends