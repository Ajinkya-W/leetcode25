class Solution {
private:
    void dfsHelper(const vector<vector<char>> &grid, vector<vector<bool>> &visited, int r, int c, int numRows, int numCols){
        visited[r][c] = 1;
        int dcol[4]={0,1,-1,0};
        int drow[4]={1,0, 0,-1};
        for(int i=0; i < 4; i++){
            int newr = drow[i]+r;
            int newc = dcol[i]+c;
            if(newr<numRows && newr>=0 && newc>=0 && newc<numCols && grid[newr][newc]=='1' && !visited[newr][newc])
                dfsHelper(grid, visited, newr, newc, numRows, numCols);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands =0;
        const int numRows=grid.size(), numCols=grid[0].size();
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),0));
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(!visited[r][c] && grid[r][c]=='1'){
                    islands++;
                    dfsHelper(grid, visited, r, c, numRows, numCols);
                }
            }
        }
        return islands;
    }
};