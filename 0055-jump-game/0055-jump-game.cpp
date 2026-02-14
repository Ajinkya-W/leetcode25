class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxReach = 0;
        for(int i = 0; i < n; i++){
            if(maxReach < i)
                return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
/*
bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> canReach(n, 0);
        canReach[0] = 1;
        for(int j = 0; j < n; j++){
            if(canReach[j])
                for(int i = 0; i <= nums[j]; i++){
                    if (j + i >= n) return true;
                    canReach[j + i] = 1;
                }
        }
        return canReach[n-1];
    }
*/
