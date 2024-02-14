//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node,vector<int>adj[] , vector<int>&visited,int c,int d)
    {
        visited[node]=1;
        
        for(auto x : adj[node])
        {
            if(node==c && x==d)
            continue;
            if(visited[x]==false)
            {
                dfs(x,adj,visited,c,d);
            }
            
        }
    }
    public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int>vis(V,0);
        dfs(c,adj,vis,c,d);
        if(vis[d]==0)
        return true;
        else
        return false;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends