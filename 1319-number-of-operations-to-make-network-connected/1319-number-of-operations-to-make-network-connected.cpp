class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }
    bool unite(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx == rooty) return false; // already connected
        
        if(rank[rootx] > rank[rooty]){
            parent[rooty] = rootx;
        } else if(rank[rooty] < rank[rootx]){
            parent[rootx] = rooty;
        } else {
            parent[rooty] = rootx;
            rank[rootx]++;
        }
        return true;
    }
};
class Solution {
public:
    int makeConnected(int nodes, vector<vector<int>>& connections) {
        int edges = connections.size();
        int minEdgesNeeded = nodes - 1;
        if(minEdgesNeeded > edges){
            return -1;
        }
        DisjointSet ds(nodes);
        int totalComponents = nodes;
        for(auto& edge: connections){
            int from = edge[0], to = edge[1];
            if(ds.unite(from, to)){
                totalComponents--;
            }
        }
        return totalComponents - 1;
    }
};