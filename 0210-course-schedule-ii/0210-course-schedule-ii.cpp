class Solution {
public:
    // return has cycle as true
    bool topoDFS(unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursion, vector<int>& order, int src){
        visited[src] = 1;
        inRecursion[src] = 1;

        for(int &v: adj[src]){
            if(!visited[v] && topoDFS(adj, visited, inRecursion, order, v))
                return true;
            else if(inRecursion[v])
                return true;
        }
        inRecursion[src] = 0;
        order.push_back(src);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            // {1, 0} u, v
            // 0 -> 1 v -> u

            adj[v].push_back(u);
        }

        vector<int> order;

        vector<bool> inRecursion(numCourses, 0), visited(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(!visited[i] && topoDFS(adj, visited, inRecursion, order, i)){
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};