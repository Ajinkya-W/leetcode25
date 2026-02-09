class Solution {
private:
    void bfs(vector<vector<int>>& matrix, vector<bool>& visited, int curr){
        visited[curr] = 1;

        queue<int> q;
        q.push(curr);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v = 0; v < matrix[u].size(); v++){
                if(!visited[v] && matrix[u][v] == 1){
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        int provinces = 0;
        vector<bool> visited(V, 0);

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bfs(isConnected, visited, i);
                provinces++;
            }
        }
        return provinces;
    }
};