//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(int i,string S,vector<string> &ans){
	        if(i>=S.length()){
	            ans.push_back(S);
	            return;
	        }
	        for(int index=i;index<S.length();index++){
	            if(index>i&&S[i]==S[index]) continue;
	            swap(S[index],S[i]);
	            solve(i+1,S,ans);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    sort(S.begin(),S.end());
		    solve(0,S,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends