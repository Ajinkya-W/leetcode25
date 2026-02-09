class Solution {
private:
    void bfs(vector<vector<int>>& adj, vector<bool>& visited, int curr){
        visited[curr] = 1;

        queue<int> q;
        q.push(curr);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v: adj[u]){
                if(!visited[v]){
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
        vector<vector<int>> adj(V);
        for(int i = 0; i < V; i++){ // make V/2
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int provinces = 0;
        vector<bool> visited(V, 0);

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bfs(adj, visited, i);
                provinces++;
            }
        }
        return provinces;
    }
};