class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2){
            return max(nums[0], nums[1]);
        }

        int beforePrevSum = nums[0], prevSum = max(nums[0], nums[1]), currSum;

        for(int curr = 2; curr < n; curr++){
            currSum = max(nums[curr] + beforePrevSum, prevSum);
            beforePrevSum = prevSum;
            prevSum = currSum;
        }
        return currSum;
    }
};