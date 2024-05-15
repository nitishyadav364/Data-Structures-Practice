//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    vector<int> ans;
    void merge(int l,int mid,int h,vector<pair<int,int>> &a)
    {
        vector<pair<int,int>> temp;
        int i=l,j=mid+1;
        int len=h-l+1;
        while(i<=mid && j<=h)
        {
            if(a[i].first<a[j].first)
            {
                temp.push_back(a[i]);
                ans[a[i].second]+=(h-j+1);
                i++;
            }
            else
            {
                temp.push_back(a[j]);
                j++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(a[i]);
            ans[a[i].second]+=(h-j+1);
            i++;
        }
        while(j<=h)
        {
            temp.push_back(a[j]);
            j++;
        }
        i=l;
        int k=0;
        while(k<len)
        {
            a[k+l]=temp[k];
            k++;
        }
    }
    
    void mergesort(int l,int h,vector<pair<int,int>> &a)
    {
        if(l>=h)return;
        int mid=(l+h)/2;
        mergesort(l,mid,a);
        mergesort(mid+1,h,a);
        merge(l,mid,h,a);
    }
    vector<int> findSurpasser(int arr[], int n) {
       ans.resize(n,0);
       vector<pair<int,int>> a;
       for(int i=0;i<n;i++)
       {
           a.push_back({arr[i],i});
       }
       mergesort(0,n-1,a);
       return ans;
        
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findSurpasser(arr, n);
        for (auto i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}


// } Driver Code Ends