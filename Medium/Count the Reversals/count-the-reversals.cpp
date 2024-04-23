//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    if(s.length()%2!=0) return -1;
 stack<char> st;
  int i=0;
  int c1=0;
  int c2=0;
  int ans=0;
  while(i<s.length()){
      if(s[i]=='{'){
          st.push('{');
          c1++;
      }
      else{
          if(!st.empty()&&st.top()=='{'){
              st.pop();
              c1--;
          }
          else{
              c2++;
          }
      }
     i++;
      
  }
   int temp1=c1%2;
      int temp2=c2%2;
      ans+=c1/2;
      ans+=c2/2;
      ans+=temp1+temp2;
      return ans;
}