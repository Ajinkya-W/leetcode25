class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> canReach(n, 0);
        canReach[0] = 1;
        for(int j = 0; j < n; j++){
            if(canReach[j])
                for(int i = 0; i <= nums[j]; i++){
                    if (j + i >= n) break;
                    canReach[j + i] = 1;
                }
        }
        return canReach[n-1];
    }
};