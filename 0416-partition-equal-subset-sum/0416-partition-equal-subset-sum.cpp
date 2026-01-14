class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int num : nums) {
            target += num;
        }
        if (target % 2 != 0) {
            return false;
        }

        target /= 2;
        vector<bool> dp(target + 1, 0);
        
        for(int i = 0; i < nums.size(); i++){
            dp[0] = true;
            for(int j = target; j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};