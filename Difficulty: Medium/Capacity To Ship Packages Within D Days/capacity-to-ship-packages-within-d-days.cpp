//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int weights[], int n, int days) {
        long long sum=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
             sum+=weights[i];
        }
        int low=1;
        int high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int sumtemp=0;
            int dayscount=0;
            for(int i=0;i<n;i++){
                sumtemp+=weights[i];
                if(weights[i]>mid){
                    dayscount=1e7;
                    break;
                }
                if(sumtemp>mid){
                    dayscount++;
                    sumtemp=weights[i];
                }
            }
            if(sumtemp>0){
                dayscount++;
            }
            if(dayscount>days){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans==INT_MAX?-1:ans;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends