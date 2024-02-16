//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<char> st;
    int i = 0;
    while (i < s.length()) {
        if (s[i] == '[' || (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')) {
            st.push(s[i]);
        } else if (s[i] == ']') {
            string temp = "";
            // Check if stack is empty before accessing top element
            while (!st.empty() && st.top() >= 'a' && st.top() <= 'z') {
                temp += st.top();
                st.pop();
            }
            // Check if stack is empty before accessing top element
            if (!st.empty()) {
                st.pop(); // Remove the '['
            }
            reverse(temp.begin(), temp.end());
            string number = "";
            // Check if stack is empty before accessing top element
            while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
                number += st.top();
                st.pop();
            }
            reverse(number.begin(), number.end());
            int num = stoi(number);
            // Check if stack is empty before accessing top element
            string final = temp;
            while (num > 1) {
                final += temp;
                num--;
            }
            int x = 0;
            while (x != final.length()) {
                st.push(final[x]);
                x++;
            }
        }
        i++;
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end()); // Reverse the result
    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends