//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long totalmax(vector<int> &arr,int n)
   {
       stack<int>st1,st2;
       vector<int>left(n,0);
       vector<int>right(n,0);
       st1.push(0);
       left[0]=1;
       
       for(int i=1;i<n;i++)
       {
           while(st1.empty()==false && arr[i]>=arr[st1.top()])
           {
               st1.pop();
           }
           
           left[i]=st1.empty()?i+1:i-st1.top();
           st1.push(i);
       }
       
       right[n-1]=1;
       st2.push(n-1);
       
       for(int i=n-2;i>=0;i--)
       {
           while(st2.empty()==false && arr[i]>arr[st2.top()])
           {
               st2.pop();
           }
           
           right[i]=st2.empty()? n-i:st2.top()-i;
           st2.push(i);
       
       }
       
      long long ans=0;
      
      for(int i=0;i<n;i++)
      {
          ans=ans+(left[i]*right[i])*arr[i];
      }
      
      
      return ans;
       
       
   }
   
   
   
   long long totalmin(vector<int> &arr,int n)
   {
       stack<int>st1,st2;
       vector<int>left(n,0);
       vector<int>right(n,0);
       st1.push(0);
       left[0]=1;
       
       for(int i=1;i<n;i++)
       {
           while(st1.empty()==false && arr[i]<=arr[st1.top()])
           {
               st1.pop();
           }
           
           left[i]=st1.empty()?i+1:i-st1.top();
           st1.push(i);
       }
       
       right[n-1]=1;
       st2.push(n-1);
       
       for(int i=n-2;i>=0;i--)
       {
           while(st2.empty()==false && arr[i]<arr[st2.top()])
           {
               st2.pop();
           }
           
           right[i]=st2.empty()? n-i:st2.top()-i;
           st2.push(i);
       
       }
       
      long long ans=0;
      
      for(int i=0;i<n;i++)
      {
          ans=ans+(left[i]*right[i])*arr[i];
      }
      
      
      return ans;
       
       
   }
   
   
    long long subarrayRanges(int N, vector<int> &arr) {
        
        return totalmax(arr,N)-totalmin(arr,N);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends