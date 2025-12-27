class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dp(r, vector<int> (c));
        int maxSide = 0;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i==0 || j==0 || matrix[i][j] == '0'){
                    dp[i][j] = matrix[i][j] - '0'; 
                } 
                else{
                    int diag = dp[i-1][j-1];
                    int up = dp[i-1][j];
                    int left = dp[i][j-1];
                    dp[i][j] = 1 + min(up, min(left, diag));
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
        return maxSide * maxSide;
    }
};