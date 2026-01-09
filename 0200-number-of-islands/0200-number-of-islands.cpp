class Solution {
private:
    void dfsIslands(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &visited){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j]){
            return;
        }
        visited[i][j] = 1;
        
        dfsIslands(grid, i-1, j, visited);
        dfsIslands(grid, i+1, j, visited);
        dfsIslands(grid, i, j-1, visited);
        dfsIslands(grid, i, j+1, visited);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0, row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    islands++;
                    dfsIslands(grid, i, j, visited);
                }
            }
        }
        return islands;
    }
};