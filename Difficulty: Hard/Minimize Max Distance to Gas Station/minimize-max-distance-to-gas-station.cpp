//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     private:
    
    int noOfgasStations(vector<int> &arr, double long dist){
    int cnt = 0;
    for(int i=1; i<arr.size(); i++){

        int noInBetween = ((arr[i] - arr[i - 1]) / dist);
        if(((arr[i] - arr[i - 1]) / dist) == noInBetween * dist){
            noInBetween--;
        } 
        cnt += noInBetween;

    }

        return cnt;

    }
    
    public:
    
    double findSmallestMaxDist(vector<int> &arr, int k) {
        
        int n = arr.size();

        long double s = 0, e = 0;
        for(int i=0; i<n-1; i++){
            long double diff = (long double)arr[i + 1] - arr[i];
            e = max(e, diff);
        }
    
        long double diff = 1e-6;
    
        while(e - s > diff){
    
            long double mid = (s + e) / 2.0;
    
            int cnt = noOfgasStations(arr, mid);
            if(cnt > k){
                s = mid;
            }
            else{
                e = mid;
            }
    
        }
    
        return e;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends