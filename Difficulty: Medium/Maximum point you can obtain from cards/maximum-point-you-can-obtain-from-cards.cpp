//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &arr, int N, int k) {
       long long ans=INT_MIN;
       int size=k;
       long long temp=0;
       for(int i=0;i<k;i++){
           temp+=arr[i];
       }
       ans=max(ans,temp);
       if(k==N){
           return ans;
       }
       for(int i=0;i<k;i++){
           temp-=arr[k-i-1];
           temp+=arr[N-1-i];
           ans=max(ans,temp);
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends