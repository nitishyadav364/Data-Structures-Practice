//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int s=0;
        int e=1e9;
        int mid=0;
        while(s<=e){
            mid = (s+e)/2;
            int hourtaken=0;
            for(int i=0;i<N;i++){
                double pile =(double)piles[i];
                double m = (double)mid;
                hourtaken+= ceil(pile/m);
            }
            if(hourtaken>H){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

        }
        return s;
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