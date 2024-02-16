//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        stack<pair<char,int>>st;
        int i=0;
        while(i!=s.length()){
            if(st.empty()){
                st.push({s[i],1});
            }
            else{
                if(st.top().first==s[i]){
                    st.top().second++;
                }
                else{
                    st.push({s[i],1});
                }
            }
            if(st.top().second>=k){
                        st.top().second=st.top().second%k;
                    }
                    if(st.top().second==0) st.pop();
             i++;
        }
       
         string ans="";
    while(!st.empty()){
        while(st.top().second--){
            ans+=st.top().first;
        }
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
   

};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends