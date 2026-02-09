class Solution {
private:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int curr){
        if(visited[curr]) return;
        visited[curr] = 1;

        for(int &v: adj[curr]){
            dfs(adj, visited, v);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected[0].size();
        vector<vector<int>> adj(V);
        for(int i = 0; i < isConnected.size(); i++){
            int u = i;
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[u].push_back(j);
                }
            }
        }
        int provinces = 0;
        vector<bool> visited(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                provinces++;
            }
        }
        return provinces;
    }
};