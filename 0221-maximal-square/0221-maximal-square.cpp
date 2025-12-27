class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<int> dp(c, 0);
        int maxSide = 0;
        
        for(int i = 0; i < r; i++){
            int diag = 0;
            for(int j = 0; j < c; j++){
                int currUp = dp[j];
                if(matrix[i][j]=='0'){
                    dp[j] = 0;
                } else{
                    if(i==0 || j==0){
                        dp[j] = 1;
                    } else{
                        dp[j] = 1 + min({dp[j], dp[j-1], diag});
                    }
                }
                maxSide = max(maxSide, dp[j]);
                diag = currUp;
            }
        }
        return maxSide * maxSide;
    }
};