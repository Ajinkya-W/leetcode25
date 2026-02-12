class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int curr){
        visited[curr] = 1;
        for(int v = 0; v < isConnected[curr].size(); v++){
            if(!visited[v] && isConnected[curr][v] == 1){
                dfs(isConnected, visited, v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> visited(V, 0);
        int provinces = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(isConnected, visited, i);
                provinces++;
            }
        }
        return provinces;
    }
};