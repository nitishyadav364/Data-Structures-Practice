//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    vector<int>v,v2;
    for(int i=0;i<n;i++)
    {
        int key=arr[i];
        v.push_back(key);
    }
    sort(v.begin(),v.end());
    v2.push_back(-1);
    v2.push_back(-1);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=v[i])
        {
            if(v2[0]==-1)
            {
                v2[0]=i;
            }
            v2[1]=i;
        }
    }
    if(v2[0]==-1&&v2[1]==-1)
    {
        v2[0]=0;
        v2[1]=0;
        return v2;
    }
    return v2;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends