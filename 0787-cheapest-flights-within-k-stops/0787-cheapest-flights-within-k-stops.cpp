class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        
        queue<pair<int, int>> q; // {node, current_total_cost}
        q.push({src, 0});

        int stops = 0;
        // The Truth: stops <= k allows for k+1 total edges
        while(!q.empty() && stops <= k) {
            int sz = q.size();
            while (sz--) {
                auto [currNode, currCost] = q.front();
                q.pop();

                for (auto& [neighbor, price] : adj[currNode]) {
                    if (currCost + price < distance[neighbor]) {
                        distance[neighbor] = currCost + price;
                        q.push({neighbor, distance[neighbor]});
                    }
                }
            }
            stops++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst]; 
    }
};