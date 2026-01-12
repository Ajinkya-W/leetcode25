class Solution {
private:
    int time = 0;
    
    // p2:dfs function inits and prep
    void dfs(vector<vector<int>>& adj, vector<bool> &visited, vector<vector<int>> &bridges, vector<int> &tin, vector<int> &low, int p, int u){
        visited[u] = 1;
        tin[u] = low[u] = time++;

        // p3:condition for trajan algo ie check if time now and update on backtrack
        // else check if we can reach to same node with less or equal time value, if not then that bridge add to solution set
        for(int neighbour: adj[u]){
            if(neighbour != p){
                if(!visited[neighbour]){
                    dfs(adj, visited, bridges, tin, low, u, neighbour);
                    low[u] = min(low[u], low[neighbour]);
                    if(low[neighbour] > tin[u]){
                        bridges.push_back({u, neighbour});
                    }
                } else{
                    low[u] = min(low[u], low[neighbour]);
                }                
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // p0:edge list to adj list
        
        vector<vector<int>> adj(n);
        int r = connections.size();
        for(int i = 0; i < r; i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        // p1:initialisation for dfs function and call
        vector<bool> visited(n, 0);
        vector<vector<int>> bridges;
        vector<int> tin(n), low(n);
        dfs(adj, visited, bridges, tin, low, -1, 0);
        
        return bridges;
    }
};