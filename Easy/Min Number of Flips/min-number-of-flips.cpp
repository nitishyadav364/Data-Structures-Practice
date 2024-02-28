//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    int e0=0, o0 = 0;
    
    // compare with the pattern starting with 0 
    for(int i = 0; i<S.size();i++)
    {
        char expected = (i%2==0)? '0' : '1';
        if(S[i] == expected) e0++;
    }
    // compare with the pattern starting with 1 
    for(int i = 0; i<S.size();i++)
    {
        char expected = (i%2==0)? '1' : '0';
        if(S[i] == expected) o0++;
    }
    // now return the number of changes we have to make in each of the pattern
    int n = S.size();
    return min(n-e0,n-o0);
}