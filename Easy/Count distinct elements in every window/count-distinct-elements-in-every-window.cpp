//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
         unordered_map<int,int>mp;
        vector<int> v;
        for(int i=0;i<k;i++){
         mp[A[i]]++;
        }
       
        
        for(int i=k;i<n;i++){
            // push map size into the map
             v.push_back(mp.size());
            // remove first element
            if(mp[A[i-k]]>1)
            mp[A[i-k]]--;
            else{
             mp.erase(A[i-k]);
            }
            // add element
            mp[A[i]]++;
        }
         v.push_back(mp.size());
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends