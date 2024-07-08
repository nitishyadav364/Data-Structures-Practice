//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int poww(int mid,int n,int m){
	    long long int num=1;
	    while(n>0){
	        num=num*mid;
	        if(num>m){
	            return INT_MAX;
	        }
	        n--;
	    }
	    return num;
	}
	int NthRoot(int n, int m)
	{
	    int low=0;
	    int high=m;
	    int mid;
	    while(low<=high){
	        mid=low+(high-low)/2;
	        int x=poww(mid,n,m);
	        if(x==m){
	            return mid;
	        }
	        else if(x>m){
	            high=mid-1;
	        }
	        else{
	            low=mid+1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends