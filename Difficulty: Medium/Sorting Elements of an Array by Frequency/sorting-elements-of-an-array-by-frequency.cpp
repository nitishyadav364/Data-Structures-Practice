//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
        static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        if(a.second == b.second)
        {
            return (a.first<b.first);
        }
        return (a.second>b.second);
    }
    
    vector<int> sortByFreq(int arr[],int n)
    {
        map<int, int> mp1;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            mp1[arr[i]]++;
        }
        
        vector<pair<int, int>> v1;
        for(auto itr : mp1)
        {
            v1.push_back(itr);
        }
        sort(v1.begin(), v1.end(), cmp);
        for(auto itr : v1)
        {
            int tmp = itr.second;
            while(tmp>0)
            {
                res.push_back(itr.first);
                tmp--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends