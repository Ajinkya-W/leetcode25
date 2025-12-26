class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int minutes = 0, freshOranges = 0;
        queue<pair<int, int>> q;

        // precompute
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        if(freshOranges==0) return 0;
        
        // rot
        while(!q.empty()){
            int qSize = q.size();
            
            for(int i = 0; i < qSize; i++){
                int r = q.front().first, c = q.front().second;
                
                if(r-1>=0 && grid[r-1][c] == 1){
                    grid[r-1][c] = 2; q.push({r-1, c}); freshOranges--;
                }
                if(r+1<row && grid[r+1][c] == 1){
                    grid[r+1][c] = 2; q.push({r+1, c}); freshOranges--;
                }
                if(c-1>=0 && grid[r][c-1] == 1){
                    grid[r][c-1] = 2; q.push({r, c-1}); freshOranges--;
                }
                if(c+1<col && grid[r][c+1] == 1){
                    grid[r][c+1] = 2; q.push({r, c+1}); freshOranges--;
                }
                q.pop();
            }
            if(!q.empty())
                minutes++;
        }
        
        return freshOranges > 0? -1: minutes;
    }
};