//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int search(string text, string pat)
	{
	   
         int n = text.length();
	    int len = 0;
	    int t = 0;
	    for(int i =0;i<n;i++){
	        if(text[i]==pat[t]){
	            t++;
	            len++;
	            if(len==pat.length()){
	                return 1;
	            }
	        }else{
	             if (len > 0) {
                i = i - len;  // Move back the index in the text
            }
	            t=0;
	            len=0;
	        }
	    }
	    return 0;
	    
	    
       
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string x, y;
   		cin >> x >> y;



        Solution ob;
   		cout << ob.search(x, y) << "\n";
   	}

    return 0;
}
// } Driver Code Ends