class Solution {
public:
    bool bfs(vector<vector<int>>& adj, vector<int> &color, int curr, int currColor){
        queue<int> q;
        q.push(curr);
        color[curr] = currColor;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v: adj[u]){
                if(color[v] == color[u])
                    return false;
                else if(color[v] == -1){
                    q.push(v);
                    color[v] = 1 - color[u];
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++){
            if(color[i] == -1 && !bfs(adj, color, i, 0)){
                return false;
            }
        }
        return true;
    }
};