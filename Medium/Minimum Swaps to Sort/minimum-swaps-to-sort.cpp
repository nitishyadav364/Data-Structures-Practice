//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int, int>> p;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            p.push_back({nums[i], i});
        }
        sort(p.begin(), p.end());
        
        for(int i = 0; i < nums.size(); i++){
            if(i == p[i].second)
                continue;
            
            else {
                count++;
                swap(p[i], p[p[i].second]);
                i--;
            }
        }
        return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends