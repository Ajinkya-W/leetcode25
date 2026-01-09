class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        int prev = nums[0], beforePrev = 0;
        
        for(int i = 1; i < n; i++){
            int curr = max(nums[i] + beforePrev, prev);
            beforePrev = prev;
            prev = curr;
        }
        return prev;
    }
};