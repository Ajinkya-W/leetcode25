class Solution {
private:
    void dfsHelper(vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c, int numRows, int numCols, int originalColor, int color){
        visited[r][c] = 1;
        int dcol[4]={0,1,-1,0};
        int drow[4]={1,0, 0,-1};
        for(int i=0; i < 4; i++){
            int newr = drow[i]+r;
            int newc = dcol[i]+c;
            if(newr<numRows && newr>=0 && newc>=0 && newc<numCols && !visited[newr][newc] && grid[newr][newc]==originalColor){
                grid[newr][newc] = color;
                dfsHelper(grid, visited, newr, newc, numRows, numCols, originalColor, color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        const int numRows=grid.size(), numCols=grid[0].size();
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),0));
        int originalColor = grid[sr][sc];
        dfsHelper(grid, visited, sr, sc, numRows, numCols, originalColor, color);
        grid[sr][sc] = color;
        return grid;
    }
};