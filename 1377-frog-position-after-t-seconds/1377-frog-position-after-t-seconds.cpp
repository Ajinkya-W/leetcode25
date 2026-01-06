class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<pair<int, pair<int, double>>> q;
        q.push({1, {0, 1.0}});

        int time = 0;
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i < qSize; i++){
                auto front = q.front();
                q.pop();

                int curr = front.first;
                int parent = front.second.first;
                double prob = front.second.second;

                int childrenCount = 0;
                for (int neighbor : adj[curr]) {
                    if (neighbor != parent) childrenCount++;
                }

                if (curr == target) {
                    // If time is exact, or we are at a leaf and time is remaining
                    if (time == t || (time < t && childrenCount == 0)) return prob;
                    return 0.0; // Must jump away if not a leaf
                }
                if (time < t && childrenCount > 0) {
                    for (int neighbor : adj[curr]) {
                        if (neighbor != parent) {
                            q.push({neighbor, {curr, prob / childrenCount}});
                        }
                    }
                }
            }
            time++;
        }
        return 0.0;
    }
};