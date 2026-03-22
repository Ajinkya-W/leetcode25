class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        const int maxXor = 16384;
        const int inf = 1e9;
        vector<int> dp(maxXor, inf);

        dp[0] = 0;
        
        for(int num: nums){
            vector<int> nextDP(maxXor, inf);
            for(int v = 0; v < maxXor; v++){
                if(dp[v] >= inf) continue;

                nextDP[v ^ num] = min(nextDP[v ^ num], dp[v]);
                nextDP[v] = min(nextDP[v], dp[v] + 1);
            }
            dp = move(nextDP);
        }
        return dp[target] >= inf? -1: dp[target];
    }
};
