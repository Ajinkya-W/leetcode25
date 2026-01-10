// Time: O(E \alpha(N) + E log E) — Where $E$ is the total number of emails. The log E from sorting is the actual bottleneck, not the DSU.
// Space: O(E + N) — To store the email map and the DSU parent/rank arrays.
class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank; // Added for optimization
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot != yRoot) {
            if(rank[xRoot] > rank[yRoot]){
                parent[yRoot] = xRoot;
            } else if(rank[xRoot] < rank[yRoot]) {
                parent[xRoot] = yRoot;
            } else{
                parent[yRoot] = xRoot;
                rank[xRoot]++;
            }
        }
    }
};
class Solution {

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSet ds(n);
        unordered_map<string, int> emailMap; // email to index map

        // Phase 1: Build the connectivity graph using account indices    
        for (int i = 0; i < n; i++) {
            const auto& account = accounts[i];
            for (int j = 1; j < account.size(); j++) {
                const string& email = account[j];
                auto itr = emailMap.find(email);
                if (itr == emailMap.end()) {
                    emailMap[email] = i;
                } else {
                    // Email seen before: Bridge found. 
                    // Merge current account index with the previously mapped account index.
                    ds.unite(i, itr->second);
                }
            }
        }
        // Phase 2: Group account indices by their absolute representative (root)

        unordered_map<int, vector<int>> rootChildMap;
        for (int child = 0; child < ds.parent.size(); child++) {
            int root = ds.find(child);
            rootChildMap[root].push_back(child);
        }

        vector<vector<string>> resultAccounts;

        for (const auto& [root, children] : rootChildMap){

            vector<string> currentComponentEmails;

            for (const auto& child : children){
                const vector<string>& emails = accounts[child];
                currentComponentEmails.insert(currentComponentEmails.end(), emails.begin()+1, emails.end());
            }
            sort(currentComponentEmails.begin(), currentComponentEmails.end());
            currentComponentEmails.erase(unique(currentComponentEmails.begin(), currentComponentEmails.end()), currentComponentEmails.end());

            vector<string> emailRow;

            emailRow.push_back(accounts[root][0]);
            emailRow.insert(emailRow.end(), currentComponentEmails.begin(), currentComponentEmails.end());
            
            resultAccounts.push_back(emailRow);
        }
        return resultAccounts;
    }
};