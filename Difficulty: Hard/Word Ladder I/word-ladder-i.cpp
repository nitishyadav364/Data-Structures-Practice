//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        if(startWord.length()!=targetWord.length()){
            return -1;
        }
        if(startWord==targetWord){
            return 0;
        }
        map<string,int>mp;
        for(int i=0;i<wordList.size();i++){
            mp[wordList[i]]=1;
        }
        queue<pair<string,int>>que;
        que.push({startWord,1});
        while(!que.empty()){
            auto temp=que.front();
            que.pop();
            string curr=temp.first;
            int currLen=temp.second;
            if(curr==targetWord){
                return currLen;
            }
            for(int i=0;i<curr.length();i++){
                for(int j=0;j<26;j++){
                    char temp_char=curr[i];
                    curr[i]=j+'a';
                    if(mp[curr]==1){
                        mp.erase(curr);
                        que.push({curr,currLen+1});
                    }
                    curr[i]=temp_char;
                }
                
            }
        }
        return 0;
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