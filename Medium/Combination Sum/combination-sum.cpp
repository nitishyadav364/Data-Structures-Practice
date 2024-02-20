//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int i,vector<int> &temp,vector<int>&A,vector<vector<int>> &ans,int B){
        if(B==0){
            ans.push_back(temp);
            return;
        }
        if(i==A.size()||B<0){
            return;
        }
        temp.push_back(A[i]);
        solve(i,temp,A,ans,B-A[i]);
        temp.pop_back();
         while(i+1<A.size()&&A[i]==A[i+1]){
            i++;
         }
        solve(i+1,temp,A,ans,B);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0,temp,A,ans,B);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends