class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> dp(c+1, 0);
        int maxSide = 0;

        for(int i = 1; i <= r; i++){
            int diag = 0;
            for(int j = 1; j <= c; j++){
                int currUp = dp[j];
                
                if(matrix[i-1][j-1]=='1')
                    dp[j] = 1 + min({dp[j], dp[j-1], diag});
                else dp[j] = 0;

                maxSide = max(maxSide, dp[j]);
                diag = currUp;
            }
        }
        return maxSide * maxSide;
    }
};