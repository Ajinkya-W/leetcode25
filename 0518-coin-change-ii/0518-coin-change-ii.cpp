class Solution {
public:
    int rec(vector<int> &coins, int currIndex, int rem, vector<vector<int>>& dp){
        if(rem == 0) return 1;
        if(rem < 0) return 0;
        if(currIndex == coins.size()) return 0;

        if(dp[currIndex][rem] != -1) return dp[currIndex][rem];

        int total = 0;

        for(int i = currIndex; i < coins.size(); i++){
            total += rec(coins, i, rem - coins[i], dp);
        }
        return dp[currIndex][rem] = total;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(
            coins.size(),
            vector<int> (amount + 1, -1));
        return rec(coins, 0, amount, dp);
    }
};