//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<int>adjacency[],int i,vector<int>&visited){
        visited[i]=1;
        for(auto it:adjacency[i]){
            if(!visited[it]){
                dfs(adjacency,it,visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
       vector<int> adjacency[V+1];
       for(int i=0;i<adj.size();i++){
           for(int j=0;j<adj.size();j++){
               if(adj[i][j]==1){
                   adjacency[i+1].push_back(j+1);
                   adjacency[j+1].push_back(i+1);
               }
           }
       }
       int count=0;
       vector<int>visited(V+1,0);
       for(int i=1;i<=V;i++){
           if(!visited[i]){
               count++;
               dfs(adjacency,i,visited);
           }
       }
       return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends