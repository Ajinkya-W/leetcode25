class DisjointSet{
public:
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x){
            return x;
        } else{
            return parent[x] = find(parent[x]);
        }
    }
    bool unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            } else if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            } else{
                rank[rootX]++;
                parent[rootY] = rootX;
            }
            return true;
        }
        return false;
    }
};
class Solution {
private:
    int manhattanDistance(int x1, int y1, int x2, int y2) {
        return abs(x2 - x1) + abs(y2 - y1);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges;
        edges.reserve(n * (n - 1) / 2); 
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = manhattanDistance(points[i][0], points[i][1], points[j][0], points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        DisjointSet dsu(n);
        int totalWeight = 0;
        int edgesUsed = 0;

        for (auto& edge : edges) {
            int w = get<0>(edge);
            int u = get<1>(edge);
            int v = get<2>(edge);

            if (dsu.unite(u, v)) {
                totalWeight += w;
                edgesUsed++;
                
                if (edgesUsed == n - 1) break;
            }
        }
        return totalWeight;
    }
};