//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
private:
    void dfs(int s, vector<int> adj1[], vector<int> &vis)
    {
        vis[s]=1;
        for(auto x: adj1[s])
        {
            if(vis[x]==0)
            {
                dfs(x, adj1, vis);
            }
        }
    }
public:
    int isTree(int n, int m, vector<vector<int>> &adj)
    {
        // checked: number of vertices should be equal to (number of nodes -1) V=(N-1)
        // There should not be any disconnected node
        if((n-m)!=1)
        {
            return 0;
        }
        vector<int> vis(n, 0);
        vector<int> adj1[n];
        for(auto x: adj)
        {
            adj1[x[0]].push_back(x[1]);
            adj1[x[1]].push_back(x[0]);
        }
        dfs(0, adj1, vis);
        for(auto x: vis)
        {
            if(x==0)
            {
                return 0;
            }
        }
        return 1;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends