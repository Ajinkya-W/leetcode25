class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        return max(robNormal(nums, 0, n - 1), robNormal(nums, 1, n));
    }
    int robNormal(vector<int>& nums, int start, int end) {

        if (0 == end - start)
            return nums[start];

        int prev = nums[start], beforePrev = 0;

        for (int i = start + 1; i < end; i++) {
            int curr = max(nums[i] + beforePrev, prev);
            beforePrev = prev;
            prev = curr;
        }
        return prev;
    }
};