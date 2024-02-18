//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(int i,int sum,vector<vector<int>>&ans,vector<int>&temp){
	    if(sum==0){
	        ans.push_back(temp);
	        return;
	    }
	    if(i<=0||sum<0) return;
	     temp.push_back(i);
	     solve(i,sum-i,ans,temp);
	     temp.pop_back();
	     solve(i-1,sum,ans,temp);
	}
    vector<vector<int>> UniquePartitions(int n) {
       vector<int>temp;
       vector<vector<int>>ans;
       solve(n,n,ans,temp);
       return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends