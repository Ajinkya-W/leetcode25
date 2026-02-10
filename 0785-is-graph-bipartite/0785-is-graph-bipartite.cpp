class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& color, int curr, int currColor){
        color[curr] = currColor;

        for(int &v: adj[curr]){
            if(color[v] == color[curr])
                return false;
            if(color[v] == -1 && !dfs(adj, color, v, 1 - currColor)){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++){
            if(color[i] == -1 && !dfs(adj, color, i, 0)){
                return false;
            }
        }
        return true;
    }
};