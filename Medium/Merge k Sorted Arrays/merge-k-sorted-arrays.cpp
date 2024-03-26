//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>min_heap;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            min_heap.push({arr[i][0],{i,0}});
        }
        int i=0;
        while(i<k*k){
            ans.push_back(min_heap.top().first);
            i++;
            int index_main=min_heap.top().second.first;
            int index_secondary=min_heap.top().second.second+1;
            min_heap.pop();
            if(arr[index_main].size()<=index_secondary){
                continue;
            }
            else{
                min_heap.push({arr[index_main][index_secondary],{index_main,index_secondary}});
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends