//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int i,vector<int>adjacen[],vector<int>&Visited){
        Visited[i]=1;
        for(auto it:adjacen[i]){
            if(!Visited[it]){
                solve(it,adjacen,Visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>Visited(V,0);
        vector<int>adjacen[V];
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j]==1){
                adjacen[i].push_back(j);
                 adjacen[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<V;i++){
            if(!Visited[i]){
                solve(i,adjacen,Visited);
                ans++;
            }
        }
        return ans;
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