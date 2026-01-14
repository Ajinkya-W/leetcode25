class Solution {
private:
    typedef pair<int, int> P;

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n <= 1)
            return 0;
        
        int finalVisitedState = (1 << n) - 1; // pow(2, n) - 1

        // Queue storing states
        queue<P> q; // node, mask

        vector<vector<bool>> visited(n, vector<bool> (finalVisitedState, 0)); // node, pathMask
        // multi source BFS
        for (int i = 0; i < n; i++) {
            int maskVal = (1 << i);

            q.push({i, maskVal});
            visited[i][maskVal] = 1;
        }
        int path = 0;

        while (!q.empty()) {
            int size = q.size();
            path++;
            while (size--) {
                auto curr = q.front();
                q.pop();
                int currNode = curr.first;
                int currMask = curr.second;
                for (int& neighbour : graph[currNode]) {
                    int nextMask = currMask | (1 << neighbour);
                    if (nextMask == finalVisitedState) {
                        return path;
                    }
                    if (visited[neighbour][nextMask] == 0) {
                        visited[neighbour][nextMask] = 1;
                        q.push({neighbour, nextMask});
                    }
                }
            }
        }
        return -1;
    }
};