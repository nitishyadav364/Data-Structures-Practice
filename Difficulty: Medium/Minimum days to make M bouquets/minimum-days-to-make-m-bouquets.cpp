//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     int solve(int M, int K, vector<int> &bloomDay){
      
      if(M*K>bloomDay.size()) return -1;
      int l=1;
      int h=*max_element(bloomDay.begin(),bloomDay.end());
      int ans=0;
      while(l<=h){
          int mid=l+(h-l)/2;
          int count=0;
          int make=0;
          for(int i=0; i<bloomDay.size(); i++){
              if(bloomDay[i]<=mid){
                  count++;
              }else{
                  make+=count/K;
                  count=0;
              }
          }
          make+=count/K;
          if(make>=M){
              ans=mid;
              h=mid-1;
          }else{
              l=mid+1;
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends