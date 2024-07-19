//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    int maxConsecutiveOnes(int n)
    {
       if(n==0)return n;
        
        int count =0, maxi =0;
        while(n>0){
            if(n%2 ==1){
                while(n%2==1 && n>0){
                    count++;
                    n/=2;
                }
                maxi= max(maxi, count);
            }
            else{
                count=0;
                n/=2;
            }
            
        }
         return maxi;
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends