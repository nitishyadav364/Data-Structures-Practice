//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      void solve(int i, int num, vector<string>& ans, string temp) {
    if (i == num) {
        ans.push_back(temp);
        return;
    }
    if (i == 0) {
        solve(i + 1, num, ans, temp + '0');
        solve(i + 1, num, ans, temp + '1');
    } else {
        if (temp[i - 1] == '1') {
            solve(i + 1, num, ans, temp + '0');
        } else {
            solve(i + 1, num, ans, temp + '0');
            solve(i + 1, num, ans, temp + '1');
        }
    }
    }
    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
        string temp="";
        solve(0,num,ans,temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends