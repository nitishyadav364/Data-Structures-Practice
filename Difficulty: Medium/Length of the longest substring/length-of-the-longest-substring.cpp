//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        int n = S.length();
    int ans = 0; // Initialize the answer to 0
    int mp[256] = {0}; // Frequency array for all ASCII characters
    int i = 0, j = 0; // Initialize the window's start and end pointers

    while (j < n) {
        mp[S[j]]++; // Increment the frequency of the current character

        // If character count is greater than 1, it means we have duplicates
        while (mp[S[j]] > 1) {
            mp[S[i]]--; // Reduce frequency of character at the start of the window
            i++; // Move the start pointer to the right
        }

        // Update the answer with the maximum length of the unique substring found so far
        ans = max(ans, j - i + 1);
        j++; // Move the end pointer to the right
    }

    return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends