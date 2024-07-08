//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     int findCount(vector<int>s,int r)
  {
      int h = 0;
    //   vector<int>s=k;
      for(int i=0;i<s.size();i++)
      {
          h += ceil((double)s[i]/(double)r);
      }
      return h;
  }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int Mx=*max_element(piles.begin(),piles.end());
        int mn = Mx;
        if(H <= piles.size() )
        {
            return Mx;
        }
        else
        {
            int s = 1;
            int l=Mx;
            int mid = s + (l-s)/2;
            while(s <= l){
                int ans=findCount(piles,mid);
                if(ans <= H) {
                    mn = min(mn,mid);
                        l= mid-1;
                    
                }
                else 
                { 
                    s = mid+1;  
                }
                mid = s + (l-s)/2;
            }
            return mn;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends