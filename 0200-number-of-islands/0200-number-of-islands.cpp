class DSU{
    vector<int> parent, ranks;
    public:
    DSU(int n){
        parent.resize(n);
        ranks.resize(n, 0);
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
        if(rootX == rootY)  return false;
        if(ranks[rootX] > ranks[rootY]){
            parent[rootY] = rootX;
        } else if(ranks[rootX] < ranks[rootY]){
            parent[rootX] = rootY;
        } else{
            parent[rootY] = rootX;
            ranks[rootX]++;
        } 
        return true;  
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        
        DSU ds(R * C);
        // we go through each bucket and see which can be combined
        int islands = 0;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(grid[r][c] == '1'){ 
                    islands++;

                    int currPosition = r * C + c;
                    int rightPosition = r * C + (c+1);
                    int downPosition = (r+1) * C + c;

                    if(c + 1 < C && grid[r][c + 1] == '1'){
                        if(ds.unite(currPosition, rightPosition)) islands--;
                    }
                    if(r + 1 < R && grid[r + 1][c] == '1'){
                        if(ds.unite(currPosition, downPosition)) islands--;
                    }
                }
            }
        }
        
        return islands;
    }
};