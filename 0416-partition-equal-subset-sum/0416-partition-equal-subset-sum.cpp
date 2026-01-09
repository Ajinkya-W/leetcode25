class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int num: nums){
            target += num;
        }
        if(target%2 != 0) return false;

        target /= 2;

        vector<bool> dp(target+1, 0);
        dp[0] = true;
        for(int num: nums)
            for(int i = target; i >= num; i--){
                dp[i] = dp[i] || dp[i-num];
            }
        return dp[target];
    }
};