class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        int freshOranges = 0, minutes = 0;
        int row = grid.size(), col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {

            int qSize = q.size();
            for (int it = 0; it < qSize; it++) {
                pair<int, int> currOrange = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int newRow = currOrange.first + dr[i];
                    int newCol = currOrange.second + dc[i];

                    if (newRow >= 0 && newRow < row && newCol >= 0 &&
                        newCol < col && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        freshOranges--;
                        q.push({newRow, newCol});
                    }
                }
            }
            if (!q.empty()) minutes++;
        }
        
        return freshOranges != 0? -1: minutes;
    }
};