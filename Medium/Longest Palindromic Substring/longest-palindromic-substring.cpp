//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string expand(string &s, int i, int j)
    {
      while(i>=0 && j<s.size() && s[i] == s[j])
      {
        i--;
        j++;
      }
      return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string S){
        // code here   
     string ans  = "";
    for(int i=0;i<S.size();i++)
    {
        //Odd
        int j=i;
        string oddExpand = expand(S,i,j);
 
        //Even
        j= i+1;
        string evenExpand = expand(S,i,j);
        if(ans.size() < oddExpand.size()) ans = oddExpand;
        if(ans.size() < evenExpand.size()) ans = evenExpand;

    
    }   
      return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends