//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    static bool custom(pair<int,int>x,pair<int,int>y){
    return ((x.second)<(y.second));
    }
    int maxChainLen(struct val p[],int n){
        //Your code here
        vector<pair<int,int>> vect;
        
        for(int i=0;i<n;i++)
        {
            vect.push_back({p[i].first,p[i].second});
        }
    
    
    
        int ans=1;
        sort(vect.begin(),vect.end(),custom);
        int end = vect[0].second;
        for(int i=0;i<vect.size();i++)
        {
    
            if(vect[i].first>end)
            {
                ans++;
                end = vect[i].second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends