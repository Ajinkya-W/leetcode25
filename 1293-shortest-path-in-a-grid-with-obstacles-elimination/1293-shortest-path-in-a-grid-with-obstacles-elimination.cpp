class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        queue<vector<int>> q;
        vector<vector<int>> maxK(row, vector<int>(col, -1));

        // 1. Initial scan: Only one source (0,0)
        q.push({0, 0, k}); 
        maxK[0][0] = k;
    
        const int dr[4] = {0, 1, -1, 0};
        const int dc[4] = {1, 0, 0, -1};
        int steps = 0;

        // 2. BFS
        while(!q.empty()){
            int qSize = q.size(); 
            
            for(int i = 0; i < qSize; i++){
                int r = q.front()[0];
                int c = q.front()[1];
                int curK = q.front()[2]; // CHANGE: track remaining k
                q.pop();

                if(r == row - 1 && c == col - 1) return steps;

                for(int j = 0; j < 4; j++){
                    int R = r + dr[j];
                    int C = c + dc[j];
                    
                    // Boundary check and validation: Only "infect" fresh oranges.
                    if(R >= 0 && R < row && C >= 0 && C < col){
                        // CHANGE: Calculate new K based on if next cell is a wall
                        int nextK = curK - grid[R][C];

                        // CHANGE: Only proceed if K is valid AND state is "stronger"
                        if(nextK >= 0 && nextK > maxK[R][C]){
                            maxK[R][C] = nextK; // Mark as visited with this strength
                            q.push({R, C, nextK});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};