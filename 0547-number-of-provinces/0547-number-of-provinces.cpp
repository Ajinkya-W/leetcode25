class DSU{
    vector<int> parent, rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(x == parent[x])
            return x;
        else{
            return parent[x] = find(parent[x]);
        }
    }
    bool unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return false;
        else{
            int rankX = rank[rootX];
            int rankY = rank[rootY];
            if(rankX > rankY){
                parent[rootY] = rootX;
            } else if(rankX < rankY){
                parent[rootX] = rootY;
            } else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
        return true;
    }
};
class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        DSU dsu(V);
        int province = V;
        for(int u = 0; u < V; u++){
            for(int v = 0; v < V; v++){
                if(isConnected[u][v] == 1 && dsu.unite(u, v)){
                    province--;
                }
            }
        }
        return province;
    }
};