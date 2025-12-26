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
        
        const int dr[4] = {0, 1, -1, 0};
        const int dc[4] = {1, 0, 0, -1};
        // rot
        while(!q.empty()){
            int qSize = q.size();
            
            for(int i = 0; i < qSize; i++){
                int r = q.front().first, c = q.front().second;
                
                for(int j = 0; j < 4; j++){
                    int R = r + dr[j];
                    int C = c + dc[j];
                    if(R >= 0 && R < row && C >= 0 && C < col && grid[R][C] == 1){
                        grid[R][C] = 2; q.push({R, C}); freshOranges--;
                    }
                    
                }
                q.pop();
            }

            if(!q.empty())
                minutes++;
        }
        
        return freshOranges > 0? -1: minutes;
    }
};