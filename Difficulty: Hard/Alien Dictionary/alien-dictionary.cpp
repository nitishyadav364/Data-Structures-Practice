//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
    map<char, vector<char>> mp;
    map<char, int> indegree;

    // Initialize indegree map for all characters
    for (int i = 0; i < K; i++) {
        indegree['a' + i] = 0;
    }

    // Build the graph and indegree map
    for (int i = 0; i < N - 1; i++) {
        int len = min(dict[i].length(), dict[i + 1].length());
        for (int j = 0; j < len; j++) {
            if (dict[i][j] != dict[i + 1][j]) {
                mp[dict[i][j]].push_back(dict[i + 1][j]);
                indegree[dict[i + 1][j]]++;
                break;
            }
        }
    }

    // Initialize the queue with nodes of in-degree 0
    queue<char> que;
    for (int i = 0; i < K; i++) {
        if (indegree['a' + i] == 0) {
            que.push('a' + i);
        }
    }

    // Perform topological sort
    string ans;
    while (!que.empty()) {
        char current = que.front();
        que.pop();
        ans += current;

        for (char neighbor : mp[current]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                que.push(neighbor);
            }
        }
    }

    // Check if there was a cycle (not all nodes are processed)
    if (ans.length() != K) {
        return "";
    }

    return ans;
}
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends