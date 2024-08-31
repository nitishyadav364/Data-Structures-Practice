//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find(int x, vector<int>& parent) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x], parent);
}

void unionByRank(int u, int v, vector<int>& parent, vector<int>& rank) {
    int par_u = find(u, parent);
    int par_v = find(v, parent);
    
    if (par_u == par_v) return;
    if (rank[par_u] > rank[par_v]) {
        parent[par_v] = par_u;
    } else if (rank[par_u] < rank[par_v]) {
        parent[par_u] = par_v;
    } else {
        parent[par_u] = par_v;
        rank[par_v]++;
    }
}

int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> vec;
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            int v = it[0];
            int wt = it[1];
            vec.push_back({wt, {i, v}});
        }
    }
    
    sort(vec.begin(), vec.end());
    
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }
    
    int sum = 0;
    for (auto it : vec) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        
        int par_u = find(u, parent);
        int par_v = find(v, parent);
        
        if (par_u != par_v) {
            sum += wt;
            unionByRank(u, v, parent, rank);
        }
    }
    
    return sum;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends