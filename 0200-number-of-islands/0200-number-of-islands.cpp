class Solution {
private:
    void dfsHelper(vector<vector<char>>& grid, vector<vector<bool>>& visited, int rows, int cols, int i, int j){
        if((i < rows && i>=0) && (j < cols && j >= 0) && !visited[i][j] && grid[i][j]=='1'){
            visited[i][j] = 1;
            dfsHelper(grid, visited, rows, cols, i+1, j);
            dfsHelper(grid, visited, rows, cols, i, j+1);
            dfsHelper(grid, visited, rows, cols, i, j-1);
            dfsHelper(grid, visited, rows, cols, i-1, j);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), numberOfIsland = 0;
        vector<vector<bool>> visited(rows, vector<bool> (cols, 0));
        for(int i = 0; i < rows; i++){
            for(int  j = 0; j < cols; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    numberOfIsland++;
                    dfsHelper(grid, visited, rows, cols, i, j);
                }
            }
        }
        return numberOfIsland;
    }
};