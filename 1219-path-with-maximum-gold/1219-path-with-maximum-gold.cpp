class Solution {
public:
    bool isValidHop(int r, int c, vector<vector<int>> &grid){
        if(r < grid.size() && c < grid[0].size() && r >= 0 && c >= 0)
            return true;
        return false;
    }
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<int>>& grid, int currGold, int &maxGold){
        visited[r][c] = true;
        currGold += grid[r][c];
        maxGold = max(maxGold, currGold);
        for(int i = 0; i < 4; i++){
            int nr = r + directions[i].first, nc = c + directions[i].second;
            if(isValidHop(nr, nc, grid) && grid[nr][nc] && !visited[nr][nc]){
                dfs(nr, nc, visited, grid, currGold, maxGold);
            }
        }
        currGold -= grid[r][c];
        visited[r][c] = false;
        return;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool> (C, false));
        int maxGold = 0;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(grid[i][j]){
                    dfs(i, j, visited, grid, 0, maxGold);
                }
            }
        }
        return maxGold;
    }
};