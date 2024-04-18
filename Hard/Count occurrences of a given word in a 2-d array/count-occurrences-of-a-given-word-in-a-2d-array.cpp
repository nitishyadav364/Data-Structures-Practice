//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(vector<vector<char>>&a,int i,int j,int n,int m,string s,int idx){

        if(i<0 || i>=n || j<0 || j>=m || a[i][j]=='$' || a[i][j]!=s[idx])

            return 0;

        if(idx==s.length()-1)

            return 1;

        char ch=a[i][j];
        int temp=0;

        a[i][j]='$';

        temp+=solve(a,i+1,j,n,m,s,idx+1);

        temp+=solve(a,i-1,j,n,m,s,idx+1);

       temp+=solve(a,i,j+1,n,m,s,idx+1);

        temp+=solve(a,i,j-1,n,m,s,idx+1);

        a[i][j]=ch;

        return temp;

    }

    int findOccurrence(vector<vector<char> > &mat, string target){

        int n=mat.size();

        int m=mat[0].size();

        int ans=0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(mat[i][j]==target[0])

                    ans+=solve(mat,i,j,n,m,target,0);

            }

        }

        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends