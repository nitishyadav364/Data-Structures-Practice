//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        if (S == 0) {
        if (D == 1) return "0";
        else return "-1"; // Impossible to have a sum of 0 with more than 1 digit
    }
    if (S > 9 * D) return "-1"; // Impossible to have a sum greater than 9*D

    string ans = "1";  
    while (D > 1) {
        ans += '0'; 
        D--;
    }

    int count = 1;
    int i = ans.length() - 1;
    while (i >= 0) {
        if (S - count == 0) break;
        if (S - count > 0) {
            if ((S - count) / 9 >= 1) {
                ans[i] = '9';
                count += 9;
            } else {
                if(i==0){
                ans[i] = '1' + (S - count);
                
                }
                else{
                     ans[i] = '0' + (S - count);
                }
                count+=S-count;
                break;
            }
        }
        i--;
    }
    if(count !=S) return "-1";
    return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends