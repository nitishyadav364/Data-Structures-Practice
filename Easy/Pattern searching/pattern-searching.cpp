//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*
str: string in which pattern we have to find pattern.
text: pattern needs to searched.
*/

bool searchPattern(string str, string pat)
{
    int i=0;
    int j=0;
    while(i<str.length()&&j<pat.length()){
        if(str[i]==pat[j]){
            int tempi=i+1;
            int tempj=j+1;
            while(tempj<pat.length()&&tempi<str.length()){
                if(str[tempi]!=pat[tempj]){
                    break;
                }
                tempi++;
                tempj++;
            }
            if(tempj==pat.length()){
                return true;
            }
        }
        i++;
    }
    return false;
}



//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}


// } Driver Code Ends