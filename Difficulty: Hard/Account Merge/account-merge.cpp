//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n);
        size.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            rank[i] = 0;
            size[i] = 1;
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void runion(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pv] > rank[pu]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    
    void sunion(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (size[pu] > size[pv]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        map<string, int> mailMap;

        // Step 1: Union accounts that share the same email address
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (mailMap.find(email) == mailMap.end()) {
                    mailMap[email] = i;
                } else {
                    ds.sunion(i, mailMap[email]);
                }
            }
        }

        // Step 2: Gather emails for each connected component
        vector<vector<string>> mergedAccounts(n);
        for (auto it : mailMap) {
            string email = it.first;
            int accountIndex = ds.find(it.second);
            mergedAccounts[accountIndex].push_back(email);
        }

        // Step 3: Prepare the final result with names and sorted emails
        vector<vector<string>> result;
        for (int i = 0; i < n; i++) {
            if (mergedAccounts[i].size() == 0) continue;
            sort(mergedAccounts[i].begin(), mergedAccounts[i].end());
            vector<string> account;
            account.push_back(accounts[i][0]); // Account name
            account.insert(account.end(), mergedAccounts[i].begin(), mergedAccounts[i].end());
            result.push_back(account);
        }

        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends