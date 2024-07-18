//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
      string str=s1+s1;
        int i=0;
        int j=0;
        while(i<str.length() && j <s2.length()){
            if(str[i]==s2[j]){
                i++;j++;
            }
            else{
                i++;
            }
        }
        
        return j==s2.length();
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends