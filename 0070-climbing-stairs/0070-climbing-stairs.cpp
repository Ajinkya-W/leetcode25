class Solution {
private:
    int climbStairsHelper(int n, vector<int>& dp){
        if(n<=1)
            return 1;
        if(dp[n-1]==-1){
            dp[n-1] = climbStairsHelper(n-1, dp);
        }
        if(dp[n-2]==-1){
            dp[n-2] = climbStairsHelper(n-2, dp);
        }
        
        return dp[n-1] + dp[n-2];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climbStairsHelper(n, dp);
    }
};