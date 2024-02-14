//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {int n=hospital.size();
        int m=hospital[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(hospital[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dx[]={1,0,-1,0};
        int dy[]={0,-1,0,1};
        int step=0;int ans=0;
        while(!q.empty())
        {
            auto it= q.front();
            int r=it.first.first;
            int c=it.first.second;
             step=it.second;
             ans=max(ans,step);
            q.pop();
            for(int k=0;k<4;k++)
            {
                int n_x=r+dx[k];
                int n_y=c+dy[k];
        if(n_x>=0 && n_x<n && n_y>=0 && n_y<m && hospital[n_x][n_y]==1 && vis[n_x][n_y]==0)
                {
               q.push({{n_x,n_y},step+1});
               vis[n_x][n_y]=1;
               hospital[n_x][n_y]=2;
                }
            }
            
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(hospital[i][j]==1)
                return -1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends