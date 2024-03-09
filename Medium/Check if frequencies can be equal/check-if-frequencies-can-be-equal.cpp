//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    vector<int>arr(26);
	    for(auto x:s)arr[x-'a']++;
	    sort(arr.begin(),arr.end());
	    int i=0;
	    while(arr[i]==0)++i;
	    
	    map<int,int>mp;
	    for(int j=i;j<26;++j)mp[arr[j]]++;
	    if(mp.size()>2)return 0;
	    if(mp.size()==1)return 1;
	    
	    for(auto x:mp){
	        if(x.first==1 && x.second==1)return 1;
	    }
	    
	    bool aa=1;
	    int a=-1,b=-1,c;
	    for(auto x:mp){
	        if(a==-1)a=x.first;
	        else b=x.first;
	        if(x.second==1)aa=0,c=x.first;
	    }
	    
	    
	    if(aa)return 0;
	   // cout<<1;
	    
	    if(c==a && b+1==a)return 1;
	    if(c==b && a+1==b)return 1;
	    return 0;
	    
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends