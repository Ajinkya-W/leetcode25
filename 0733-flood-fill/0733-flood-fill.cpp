class Solution {
    const int dcol[4]={0,1,-1,0};
    const int drow[4]={1,0, 0,-1};
private:
    void dfsHelper(vector<vector<int>> &grid, int r, int c, int numRows, int numCols, int originalColor, int color){
        grid[r][c] = color;
        for(int i=0; i < 4; i++){
            int newr = drow[i]+r;
            int newc = dcol[i]+c;
            if(newr<numRows && newr>=0 && newc>=0 && newc<numCols && grid[newr][newc]==originalColor){
                dfsHelper(grid, newr, newc, numRows, numCols, originalColor, color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        const int numRows=grid.size(), numCols=grid[0].size();
        int originalColor = grid[sr][sc];
        if (originalColor == color) {
            return grid;
        }

        dfsHelper(grid, sr, sc, numRows, numCols, originalColor, color);
        return grid;
    }
};