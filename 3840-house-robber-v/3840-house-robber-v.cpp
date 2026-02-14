class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
            
        long long beforePrev = nums[0], curr;
        long long prev = colors[0] != colors[1] ? nums[0] + nums[1] : max(nums[0], nums[1]);
        
        if (n == 2)
            return prev;

        for (int i = 2; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                curr = max(nums[i] + beforePrev, prev);
            } else {
                curr = nums[i] + prev;
            }
            beforePrev = prev;
            prev = curr;
        }
        return curr;
    }
};