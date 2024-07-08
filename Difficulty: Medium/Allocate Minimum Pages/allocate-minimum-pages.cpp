//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    //Function to find minimum number of pages.
   bool isPossible( int arr[] , int n , int m , int mid){
        
        
        int studentCount = 1;
        int pageSum = 0;
        
        for(int i= 0 ; i < n ; i++){
            if( pageSum +arr[i]<= mid){
               pageSum += arr[i];
            }
            else{
                studentCount++;
                if(studentCount>m || arr[i]>mid){
                    return false;
                }
                pageSum =arr[i];
            }
        }
        return true;
    }
    

     
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if (m > n) {
        return -1;
        }
        
        
       int s= 0 ; 
       long long  sum = 0 ; 
       for(int i= 0 ; i < n ; i++){
           sum += arr[i];
       }
       
       int e = sum;
       long long ans= -1;
       int mid = s+(e-s)/2;
       
       
       while(s<=e){
       if(isPossible(arr,n,m ,mid)){
           ans=mid;
           e=mid-1;
       }
       else{
           s=mid+1;
       }
       
       mid=s+(e-s)/2;
    }
    return ans;
    }


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends