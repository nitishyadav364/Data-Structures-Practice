//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(int i,vector<int> &vis,vector<int>adj[],vector<int>&parent){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                parent[it]=i;
                bool temp=solve(it,vis,adj,parent);
                if(temp) return true;
            }
            else if(parent[i]!=it){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V+1,0);
        vector<int> parent(V+1,-1);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool temp=solve(i,vis,adj,parent);
                if(temp) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends