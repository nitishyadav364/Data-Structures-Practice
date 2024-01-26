//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        priority_queue<pair<double,double>>pq;
        for(int i=0;i<n;i++){
            pq.push({(double)arr[i].value/double(arr[i].weight),(double)arr[i].weight});
        }
        double ans=0;
        double w=double(W);
        while(w>0&&!pq.empty()){
            pair<double,double>temp=pq.top();
            pq.pop();
            if(temp.second<w){
                ans+=temp.second*temp.first;
                w-=temp.second;
            }
            else{
                ans+=w*temp.first;
                w=0;
            }  
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends