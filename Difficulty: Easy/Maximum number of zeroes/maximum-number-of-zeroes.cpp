//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string maxZero(vector<string> &a) {
          int milf=0;
       string maxi="-1";
       int n=a.size();
       for(int i=0;i<n;i++)
       {
           int counti=0;
           string s=a[i];
           int n1=s.size();
           for(int j=0;j<n1;j++)
           {
               if(s[j]-'0'==0)
               {
                   counti++;
               }
               
           }
           if(counti>milf)
               {
                   milf=counti;
                   maxi=s;
               }
           else if(counti==milf&&counti>0)
           {
               //compare maxi,s
               int k=s.size();
               int l=maxi.size();
               if(k>l)maxi=s;
               else if(k==l)
               {
                   for(int w=0;w<k;w++)
                   {
                       int key1=s[w]-'0';
                       int key2=maxi[w]-'0';
                       if(key1>key2)
                       {
                           maxi=s;
                           break;
                       }
                       else if(key1<key2)
                       {
                           break;
                       }
                   }
               }
           }
       }
       return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        stringstream ss;
        string inputLine;
        getline(cin, inputLine);
        ss << inputLine;
        vector<string> arr;
        string numStr;
        while (ss >> numStr) {
            arr.push_back(numStr);
        }

        Solution solution;
        cout << solution.maxZero(arr) << "\n";
    }
    return 0;
}

// } Driver Code Ends