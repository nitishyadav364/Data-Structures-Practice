//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
         string ans="";
        for(int i=1;i<S.size();i++){
            string p=S.substr(0,i);
            string r=S.substr(i,S.size());
            int tp=stoi(p);
            int tr=stoi(r);
            if(tp%a==0 && tr%b==0){
                ans=p+" "+r;
                break;
            }
        }
        if(ans.size()==0)
            ans="-1";
        return(ans);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
} 
// } Driver Code Ends