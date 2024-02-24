//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
          int n=a.size();
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int prev=mid-1;
            int next=mid+1;
            if(a[mid]>=a[prev] && a[mid]>=a[next])
            return a[mid];
            else if(a[mid]<a[next])
             l=mid+1;
             else
             h=mid-1;
        }
        return -1;


    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends