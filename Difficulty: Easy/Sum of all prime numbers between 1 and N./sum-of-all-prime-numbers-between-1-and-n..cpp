//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
   	  long long int fun(int n,vector<bool> &visited){
           long long int ans;
           ans=0;
           for(int i=2;i<=n;i++){
               if(!visited[i]){
                   ans+=i;
                   
                   for(int j=i;j<=n;j+=i){
                       visited[j]=true;
                   }
                   
               }
               
           }
           return ans;
       }
       
       
       
       long long int prime_Sum(int n){
           // Code here
           vector<bool> isPrime(n+1,false);
           // long long int ans=0;
           return fun(n,isPrime);
           
       }   
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		long long int ans = ob.prime_Sum(n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends