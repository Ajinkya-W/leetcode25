class Solution {
private:
    // Finds all descendants of 'start' and marks 'start' as their ancestor.
    void dfs_find_descendants(int start, int u, vector<vector<int>> &graph, 
                              vector<vector<int>> &ancestor, vector<bool> &visited) {
        
        // This 'visited' array is only for the current traversal starting at 'start'.
        visited[u] = true;
        
        // u is NOT the ancestor we care about right now; 'start' is the ancestor.
        // We only add 'start' to the list of ancestors for its descendants (v).
        
        for (int v : graph[u]) {
            if (!visited[v]) {
                // 'start' is an ancestor of v (unless start == v, which is handled 
                // by starting the addition inside the loop of getAncestors or 
                // adding a check).
                ancestor[v].push_back(start);
                dfs_find_descendants(start, v, graph, ancestor, visited);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        // Step 1: Build the standard graph
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]); // edge[0] -> edge[1]
        }
        
        vector<vector<int>> ancestor(n);
        
        // Step 2: Run a separate DFS/BFS for EVERY potential ancestor node i.
        // This is the O(N * (N+E)) part.
        for (int i = 0; i < n; ++i) {
            // visited MUST be reset for every starting node i.
            vector<bool> visited(n, false);
            
            // The DFS should start from i, but the ancestor list addition 
            // is handled inside the recursive call logic.
            // We only need to check i's *immediate* neighbors and propagate from there.
            
            // Start DFS from i's immediate neighbors:
            for(int neighbor : graph[i]){
                 if (!visited[neighbor]) {
                     ancestor[neighbor].push_back(i); // i is a direct ancestor
                     dfs_find_descendants(i, neighbor, graph, ancestor, visited);
                 }
            }
        }
        
        // Step 3: Sort the ancestors list for each node as required by most problems of this type.
        for (int i = 0; i < n; ++i) {
            sort(ancestor[i].begin(), ancestor[i].end());
        }
        
        return ancestor;
    }
};

