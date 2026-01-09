class Solution {
public:
    // This is your core "Decision" engine
    int robNormal(vector<int>& nums, int start, int end) {
        int prev = 0;       // Best 1 step ago
        int beforePrev = 0; // Best 2 steps ago

        for (int i = start; i <= end; i++) {
            int curr = max(nums[i] + beforePrev, prev);
            beforePrev = prev;
            prev = curr;
        }
        return prev;
    }

    // HR1 (Linear)
    int rob1(vector<int>& nums) {
        return robNormal(nums, 0, nums.size() - 1);
    }

    // HR2 (Circular)
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Essential because ranges would overlap
        
        return max(robNormal(nums, 0, n - 2), 
                robNormal(nums, 1, n - 1));
    }
};