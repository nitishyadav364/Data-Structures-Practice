//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    //Function to insert heap.
    void insertHeap(int &x)
    {
        min_heap.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int max_size=max_heap.size();
        int min_size=min_heap.size();
        if(min_size==1) return;
        if(max_size+1<min_size){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        else if(min_heap.top()<max_heap.top()){
           int mini_top=min_heap.top();
           int maxi_top=max_heap.top();
           min_heap.pop();
           max_heap.pop();
           min_heap.push(maxi_top);
           max_heap.push(mini_top);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
       if(min_heap.size()==max_heap.size()){
           return (min_heap.top()+max_heap.top())/2.0;
       }
       return min_heap.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends