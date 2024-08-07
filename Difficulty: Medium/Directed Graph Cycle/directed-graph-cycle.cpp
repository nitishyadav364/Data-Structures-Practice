//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
bool solve(int i, vector<int> adj[], vector<int>& visited, vector<int>& InCallStack) {
    visited[i] = 1;
    InCallStack[i] = 1;
    for (auto it : adj[i]) {
        if (!visited[it]) {
            if (solve(it, adj, visited, InCallStack)) {
                return true;
            }
        } else if (InCallStack[it] == 1) {
            return true;
        }
    }
    InCallStack[i] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    vector<int> InCallStack(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (solve(i, adj, visited, InCallStack)) {
                return true;
            }
        }
    }
    return false;
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends