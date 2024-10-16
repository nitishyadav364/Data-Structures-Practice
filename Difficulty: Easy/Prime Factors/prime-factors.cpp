//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int> v;
        for (int i = 2; i<=sqrt(N) ; i++) {
            if (N % i == 0)
                v.push_back(i);
            while (N % i == 0)
                N /= i;
        }
        if (N != 1)
            v.push_back(N);
        return v;
    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends