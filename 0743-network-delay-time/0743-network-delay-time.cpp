class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 0th index is extra as graoh is 1-indexed

        // phase 1: Initialisation A) Build weighted 1-indexed Graph B) time vector
        vector<vector<pair<int, int>>> graph(n+1);
        for(const auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
        }
        
        vector<int> time(n+1, INT_MAX);

        time[k] = 0;

        // Phase2: enque the source node in min heap by (weights, u)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto [t, u] = pq.top();
            pq.pop();

            if (t > time[u]) continue;
            for(const auto& [v, w]: graph[u]){
                int newTime = time[u] + w;
                if(newTime < time[v]){
                    time[v] = newTime;
                    pq.push({time[v], v});
                }
            }
        }

        // Phase 3: once all heap is processed, max of distance vector, if that i INT_MAX then return -1
        int maxTime = 0;
        for(int t = 1; t <= n; t++){
            maxTime = max(time[t], maxTime);
        }
        return maxTime == INT_MAX? -1: maxTime;
    }
};