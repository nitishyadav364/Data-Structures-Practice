//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool search(string A,int i,string word){
        for(int x=0;x<word.length();x++){
            if(i<A.length()){
                if(A[i]!=word[x]){
                    return false;
                }
            }
            else{
                return false;
            }
            i++;
        }
        return true;
    }
    void solve(int i,string A,vector<string>&B,int &ans){
        if(i==A.length()){
            ans=1;
            return;
        }
        for(int x=0;x<B.size();x++){
            if(A[i]==B[x][0]){
                bool temp=search(A,i,B[x]);
                if(temp){
                    solve(i+B[x].length(),A,B,ans);
                }
            }
        }
    }
    int wordBreak(string A, vector<string> &B) {
        int ans=0;
        solve(0,A,B,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends