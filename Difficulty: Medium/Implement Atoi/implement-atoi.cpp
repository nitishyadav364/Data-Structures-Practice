//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        bool positive=true;
        int ans=0;
        for(int i=0;i<str.length();i++){
            if(str[i]==' ') continue;
            else if(str[i]=='-'){
                if(ans>0){
                    return -1;
                }
                positive=false;
            }
            else if(str[i]>'9'||str[i]<'0'){
                return -1;
            }
            else{
                ans=ans*10+str[i]-'0';
            }
        }
        return positive==true?ans:-ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends