//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
  
    
 void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        unordered_map<int,bool>row;
        unordered_map<int,bool>col;
        
        for(int i=0;i<matrix.size();i++){
              bool t=false;      
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){ 
                    t=!t;
                    break;
                }
            }
            if(t){
                row[i+1]=true;
            }else{
                row[i+1]=false;
            }
        }
        
        for(int i=0;i<matrix[0].size();i++){
              bool t=false;      
            for(int j=0;j<matrix.size();j++){
                if(matrix[j][i]==1){ 
                    t=!t;
                    break;
                }
            }
            if(t){
                col[i+1]=true;
            }else{
                col[i+1]=false;
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(row[i+1]){
                    matrix[i][j]=1;
                }
            }
        }
        
        for(int i=0;i<matrix[0].size();i++){
            for(int j=0;j<matrix.size();j++){
                if(col[i+1]){
                    matrix[j][i]=1;
                }
            }
        }
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends