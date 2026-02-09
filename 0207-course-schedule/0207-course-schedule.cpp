class Solution {
public:
    bool topoDfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursion, int src){
        visited[src] = 1;
        inRecursion[src] = 1;

        for(int &v: adj[src]){
            if(!visited[v] && topoDfs(adj, visited, inRecursion, v)){
                return true;
            } else if(inRecursion[v]){
                return true;
            }
        }
        inRecursion[src] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            // {u, v} 
            // v -> u
            adj[v].push_back(u);
        }

        vector<bool> inRecursion(numCourses, false), visited(numCourses, false);
        vector<int> order;
        bool isPossible;
        for(int i = 0; i < numCourses; i++){
            if(!visited[i] && topoDfs(adj, visited, inRecursion, i))
                return false;
        }
    
        return true;
    }
};