//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
         int res_len=0;
        string res="";
        int n = S.length();
        int l,r;
        
        for(int i=0;i<n;i++){
            l=i,r=i;
            //odd palindrome
            while(l>=0 and r<n and S[l]==S[r]){
                if((r-l+1)>res_len){
                    res = S.substr(l,r-l+1);
                    res_len = r-l+1;
                }
                l--;
                r++;
            }
            l=i,r=i+1;
            //even palindrome
            while(l>=0 and r<n and S[l]==S[r]){
                if((r-l+1)>res_len){
                    res = S.substr(l,r-l+1);
                    res_len = r-l+1;
                }
                l--;
                r++;
            }
        }
        return res;
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
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends