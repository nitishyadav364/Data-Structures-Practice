//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void add_solution(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]){
                    temp.push_back(j+1);
                }
            }
        }
        ans.push_back(temp);
    }
    bool is_safe(vector<vector<int>>&board,int row,int col,int n){
        int x=row;
        int y=col;
        while(x>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
        }
        x=row;
        y=col;
        while(x>=0&&y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        x=row;
        y=col;
        while(x>=0&&y<n){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y++;
        }
        return true;
         
    }
    void solve(vector<vector<int>>&board,vector<vector<int>> &ans,int row,int n){
        if(row==n){
            add_solution(board,ans,n);
            return;
        }
        for(int i=0;i<n;i++){
            if(is_safe(board,row,i,n)){
                board[row][i]=1;
                solve(board,ans,row+1,n);
                board[row][i]=0;
            }
        }
    }
        vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<int>> ans;
        solve(board,ans,0,n);
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends