class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        // first row
        for(int j = 0; j < n; j++)
            dp[j] = 1;
        
        for(int i = 1; i < m; i++){
            dp[0] = 1;
            for(int j = 1; j < n; j++){
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};