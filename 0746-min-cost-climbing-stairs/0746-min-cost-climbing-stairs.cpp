class Solution {
private:
    int climbStairsHelper(int n,  vector<int>& cost, vector<int>& dp){
        if(n==1 || n==0)
            return 0;
        if(dp[n-1]==-1){
            dp[n-1] = cost[n-1] + climbStairsHelper(n-1, cost, dp);
        }
        if(dp[n-2]==-1){
            dp[n-2] = cost[n-2] + climbStairsHelper(n-2, cost, dp);
        }
        
        return min(dp[n-1], dp[n-2]);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return climbStairsHelper(n, cost, dp);
    }
};