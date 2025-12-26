class Solution {
public:
        /**
        * Time Complexity: O(M * N) - Each cell is visited at most once.
        * Space Complexity: O(M * N) - In the worst case (all oranges rotten), the queue holds all cells.
    */
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int freshOranges = 0;
        queue<pair<int, int>> q;

        // 1. Initial scan: Collect all source points (rotten) and count targets (fresh).
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
    
        // Immediate return: If nothing to rot, 0 minutes have passed.
        if(freshOranges == 0) return 0;
    
        // Direction vectors for modular neighbor traversal (Up, Down, Left, Right).
        const int dr[4] = {0, 1, -1, 0};
        const int dc[4] = {1, 0, 0, -1};
        int minutes = 0;

        // 2. Multi-source BFS: Process the "rot" wave layer by layer.
        while(!q.empty()){
            int qSize = q.size(); // Snapshot size to process one full "minute" of spread.
            
            for(int i = 0; i < qSize; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int j = 0; j < 4; j++){
                    int R = r + dr[j];
                    int C = c + dc[j];
                    
                    // Boundary check and validation: Only "infect" fresh oranges.
                    if(R >= 0 && R < row && C >= 0 && C < col && grid[R][C] == 1){
                        grid[R][C] = 2; // Mutate in-place to save memory.
                        q.push({R, C});
                        freshOranges--;
                    }
                }
            }

            // Only increment time if the previous layer actually managed to spread.
            if(!q.empty())
                minutes++;
        }
    
        // If freshOranges > 0, some oranges were unreachable (isolated).
        return freshOranges > 0 ? -1 : minutes;
    }
};