//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int target)
    {
         // Your code goes here
        int front =0;
        int rear = 0;
        int minLen =INT_MAX;
        int sum =0;
        while(rear <n){
            // base case
            if(arr[rear] > target){return 1;}
            sum+=arr[rear];
            while(sum > target){
                sum-=arr[front];
                int window = rear-front+1;
                minLen = min(minLen,window);
                front++;
            }
            rear++;
        }
        return (minLen !=INT_MAX)?minLen:0;  
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends