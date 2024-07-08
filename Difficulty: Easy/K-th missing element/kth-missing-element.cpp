//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int arr[], int n, int k)
{
       int low=arr[0];
        int high=arr[0]+n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid-arr[0]>=n)
                return -1;
            int missing=arr[mid-arr[0]]-mid;
            if(missing<k)
                low=mid+1;
            else
                high=mid-1;
        }
        return high+k;
}