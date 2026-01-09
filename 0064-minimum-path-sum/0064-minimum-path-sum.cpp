class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        vector<vector<int>> dp(row, vector<int> (col, 0));
        dp[0][0] = grid[0][0];
        // first row initialisation
        for(int j = 1; j < col; j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        // first col initialisation
        for(int i = 1; i < row; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[row-1][col-1];
    }
};