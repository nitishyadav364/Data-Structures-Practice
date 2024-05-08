//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> que;
    que.push({startWord, 1}); // Start with length 1
    while (!que.empty()) {
        pair<string, int> temp = que.front();
        que.pop();
        if (temp.first == targetWord) return temp.second; // Return length when target word is found
        for (int j = 0; j < temp.first.size(); j++) {
            char tempo = temp.first[j];
            for (int i = 'a'; i <= 'z'; i++) {
                string replaced = temp.first;
                replaced[j] = i;
                if (st.find(replaced) != st.end()) {
                    st.erase(replaced);
                    que.push({replaced, temp.second + 1}); // Increment length by 1 for each transformation
                }
            }
            temp.first[j] = tempo;
        }
    }
    return 0; // Return 0 if no transformation sequence is possible
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends