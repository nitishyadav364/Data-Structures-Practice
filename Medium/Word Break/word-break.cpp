//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    bool check(int i,string string1,string string2){
        int j=0;
        while(j<string2.length()&&i<string1.length()){
            if(string1[i]!=string2[j]){
                return false;
                
            }
            else{
                i++;
                j++;
            }
        }
        if(j==string2.length()){
            return true;
        }
        return false;
    }
    bool solve(int i,string s,int n,vector<string>&dictionary){
        if(i==s.length()){
            return true;
        }
        bool ans=false;
        for(int j=0;j<dictionary.size();j++){
            if(s[i]==dictionary[j][0]){
                bool temp=check(i,s,dictionary[j]);
                if(temp) ans|=solve(i+dictionary[j].length(),s,n,dictionary);
            }
        }
        return ans;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
            return solve(0,s,n,dictionary);
             
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends