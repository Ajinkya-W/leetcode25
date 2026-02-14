class Solution {
public:
    int rec(vector<int>& nums, int currIndex, int prevEligibleIndex, vector<vector<int>> &dp){
        if(currIndex > nums.size()-1) return 0;
        if(dp[currIndex][prevEligibleIndex+1] != -1) return dp[currIndex][prevEligibleIndex+1];
        int length = 0;
        // skip
        length = 0 + rec(nums, currIndex + 1, prevEligibleIndex, dp);

        // take
        if(prevEligibleIndex == -1 || nums[prevEligibleIndex] < nums[currIndex])
            length = max(1 + rec(nums, currIndex+1, currIndex, dp), length);

        return dp[currIndex][prevEligibleIndex + 1] = length;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size()+1, -1));
        return rec(nums, 0, -1, dp);
    }
};