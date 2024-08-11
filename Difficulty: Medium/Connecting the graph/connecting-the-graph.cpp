//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int find(int x, vector<int>& parent) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x], parent);
}

void unionByRank(int u, int v, vector<int>& parent, vector<int>& rank) {
    int par_u = find(u, parent);
    int par_v = find(v, parent);
    if (par_u == par_v) return;
    if (rank[par_v] > rank[par_u]) {
        parent[par_u] = par_v;
    } else if (rank[par_u] > rank[par_v]) {
        parent[par_v] = par_u;
    } else {
        parent[par_v] = par_u;
        rank[par_u]++;
    }
}

int Solve(int n, vector<vector<int>>& edge) {
    vector<int> parent(n);
    vector<int> rank(n, 0);

    // Initialize the parent array for each node
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int redundantEdges = 0;

    // Perform union operations for each edge
    for (auto& e : edge) {
        int u = e[0];
        int v = e[1];
        int par_u = find(u, parent);
        int par_v = find(v, parent);

        if (par_u != par_v) {
            unionByRank(u, v, parent, rank);
        } else {
            redundantEdges++;
        }
    }

    // Count the number of connected components
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (find(i, parent) == i) {
            components++;
        }
    }

    // Number of edges needed to connect all components
    int neededEdges = components - 1;

    // Check if we have enough redundant edges to connect all components
    if (redundantEdges >= neededEdges) {
        return neededEdges;
    } else {
        return -1;
    }
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends