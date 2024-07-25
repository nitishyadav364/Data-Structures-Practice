//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int i,vector<int>adj[],vector<int>&visited,vector<int>&pathVisited,vector<int>&safeNode){
         visited[i]=1;
         pathVisited[i]=1;
         for(auto it:adj[i]){
             if(!visited[it]){
                 bool temp=dfs(it,adj,visited,pathVisited,safeNode);
                 if(temp){
                     safeNode[i]=0;
                     return true;
                 }
             }
             else if(pathVisited[it]){
                 safeNode[i]=0;
                 return true;
             }
         }
         safeNode[i]=1;
         pathVisited[i]=0;
         return false;
         
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
         vector<int>visited(V,0);
         vector<int>pathVisited(V,0);
         vector<int>safeNode(V,1);
         for(int i=0;i<V;i++){
             if(!visited[i]){
                 bool temp=dfs(i,adj,visited,pathVisited,safeNode);
             }
         }
         vector<int>ans;
         for(int i=0;i<V;i++){
             if(safeNode[i]==1){
                 ans.push_back(i)
;             }
         }
         sort(ans.begin(),ans.end());
         return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends