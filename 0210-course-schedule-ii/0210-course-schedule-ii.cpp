class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adj, vector<int>& inDegree) {
        queue<int> q;
        vector<int> order;

        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            order.push_back(u);

            for (int &v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (count == inDegree.size()) {
            return order;
        }
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        vector<int> inDegree(numCourses, 0);
        // build adj list
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[v].push_back(u);
            inDegree[u]++;
        }

        return topoSort(adj, inDegree);
    }
};