//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
 
class Solution
{
  public:
    long long int fn(string s,int k,int n)
    {   
        if(k<0) return 0;
        
        int i=0;
        int j=0;
        int cnt=0;
        long long int sum=0;
        int freq[26]={0};
        
        while(j<n)
        {
          freq[s[j]-'a']++;
            
            if(freq[s[j]-'a']==1) cnt++;
            
            while(cnt>k)
            {
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0) cnt--;
                i++;
            }
            j++;
            sum+=(j-i+1);
        }
        return sum;
    }

 

long long int substrCount (string s, int k)

{ 
    long long int ans=fn(s,k,s.size()) - fn(s,k-1,s.size());
    return ans; 
    }


};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends