class DisjointSet{ 
public:
    vector<int> parent;
    DisjointSet(int n){
        parent.resize(n);
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y){
        int xParent = find(x);
        int yParent = find(y);
        if(xParent != yParent){
            parent[xParent] = yParent;
        }
    }
};
class Solution {

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSet ds(n);
        unordered_map<string, int> emailMap; // email to index map

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                auto itr = emailMap.find(accounts[i][j]);
                if (itr == emailMap.end()) {
                    emailMap[accounts[i][j]] = i;
                } else{
                    ds.unite(i, emailMap[accounts[i][j]]);
                }
            }
        }
        // traverse through the ds and see parent, childs
        // that way we knw, which indexes are parent and all the ones who are childs map to same parent index
        // make parent to child map so it becomes easy to get result
        unordered_map<int, vector<int>> parentChildMap;
        for(int child = 0; child < ds.parent.size(); child++){
            int parent = ds.find(child);
            parentChildMap[parent].push_back(child);
        }

        vector<vector<string>> resultAccounts;
        for(auto index: parentChildMap){
            int parent = index.first;
            vector<int> children = index.second;
            set<string> childParentEmails;
            for(int i = 1; i < accounts[parent].size(); i++){
                childParentEmails.insert(accounts[parent][i]);
            }
            for(const auto &child: children)
                for(int i = 1; i < accounts[child].size(); i++){
                    childParentEmails.insert(accounts[child][i]);
                }
            vector<string> emailRow;
            emailRow.push_back(accounts[parent][0]);
            for(auto email: childParentEmails){
                emailRow.push_back(email);
            }
            resultAccounts.push_back(emailRow);
        }
        return resultAccounts;
    }
};