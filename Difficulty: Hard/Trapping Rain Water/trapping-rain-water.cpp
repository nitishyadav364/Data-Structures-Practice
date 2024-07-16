//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
         vector<int>leftmax(n,0);
        int leftmx=arr[0];
        for(int i=1;i<n-1;i++){
            if(leftmx>=arr[i]){
                leftmax[i]=leftmx;
            }else{
                leftmx=arr[i];
            }
        }
        vector<int>rightmax(n,0);
        int rightmx=arr[n-1];
        for(int i=n-2;i>=1;i--){
            if(rightmx>=arr[i]){
                rightmax[i]=rightmx;
            }else{
                rightmx=arr[i];
            }
        }
        long long ans=0;
        for(int i=1;i<n-1;i++){
            if(min(leftmax[i],rightmax[i])>arr[i]){
                ans+=min(leftmax[i],rightmax[i])-arr[i];
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends