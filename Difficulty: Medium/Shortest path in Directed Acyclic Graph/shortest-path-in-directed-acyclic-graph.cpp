//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     bool toposort(vector<pair<int,int>> sides[],map<int ,bool> &visited,stack<int> &st,int i){
        visited[i]=1;
        for(auto it:sides[i]){
            if(!visited[it.first]){
                toposort(sides,visited,st,it.first);
            }
        }
        st.push(i);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> sides[N];
        int u;
        int v;
        int weight;
        for(auto i:edges){
            u=i[0];
            v=i[1];
            weight=i[2];
            sides[u].push_back({v,weight});
        }
        stack<int> st;
        map<int ,bool> visited;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                toposort(sides,visited,st,i);
            }
        }
        vector<int > distance(N,INT_MAX);
        distance[0]=0;
        while(!st.empty()){
            if(distance[st.top()]==INT_MAX){
                st.pop();
                continue;
            }
            else{
                for(auto it:sides[st.top()]){
                    if(distance[st.top()]+it.second<distance[it.first]){
                       distance[it.first]=distance[st.top()]+it.second;
                    }
                }
                st.pop();
            }
        }
        for(int i=0;i<N;i++){
            if(distance[i]==INT_MAX){
                distance[i]=-1;
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends