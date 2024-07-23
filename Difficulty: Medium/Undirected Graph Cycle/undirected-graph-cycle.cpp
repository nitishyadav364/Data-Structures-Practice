//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(int i,vector<int>adj[],vector<int>&visited,vector<int>&parent){
        visited[i]=1;
        queue<int>que;
        que.push(i);
        while(!que.empty()){
            int front=que.front();
            que.pop();
            for(auto it:adj[front]){
                if(!visited[it]){
                    visited[it]=1;
                    parent[it]=front;
                    que.push(it);
                }
                else if(parent[front]!=it){
                    return true;
                }
            }
        }
        return false;
    }
bool isCycle(int V, vector<int> adj[]) {
    vector<int> parent(V, -1);
    vector<int> visited(V, 0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(solve(i,adj,visited,parent)){
                return true;
            }
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