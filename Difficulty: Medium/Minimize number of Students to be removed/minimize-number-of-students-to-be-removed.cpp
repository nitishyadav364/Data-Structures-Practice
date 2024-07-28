//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int v[], int n) {
        vector<int>ans;
        ans.push_back(v[0]);
        for(int i=1;i<n;i++)
        {
            if(ans.back()<v[i])
            {
                ans.push_back(v[i]);
            }
            else
            {
                int low = lower_bound(ans.begin(),ans.end(),v[i]) -ans.begin();
                ans[low] = v[i];
            }
        }
        return n - ans.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends