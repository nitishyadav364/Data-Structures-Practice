//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    void insertHeap(int &x)
    {
            min_heap.push(x);
            balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(min_heap.size()==1) return;
        else if((max_heap.empty()&&min_heap.size()>1)||(max_heap.size()+1<min_heap.size())){
            int temp=min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        }
        else {
            int maxi=max_heap.top();
            int mini=min_heap.top();
            if(maxi>mini){
            max_heap.pop();
            min_heap.pop();
            max_heap.push(mini);
            min_heap.push(maxi);
            }
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(min_heap.empty()) return -1;
        if(min_heap.size()>max_heap.size()) return min_heap.top();
        return (min_heap.top()+max_heap.top())/2;
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