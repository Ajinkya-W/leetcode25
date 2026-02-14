class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int jumps = 0, farthest = 0, currEnd = 0;
        for (int i = 0; i < n; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currEnd) {
                currEnd = farthest;
                jumps++;
                if (currEnd >= n - 1) return jumps;
            }
        }
        return jumps;
    }
};
/*
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumpIndexMap(n, INT_MAX);
        jumpIndexMap[0] = 0;
        for(int i  = 0; i < n; i++){
            for(int j = 0; j <= nums[i]; j++)
                if(i + j < n)
                    jumpIndexMap[i + j] = min(jumpIndexMap[i] + 1, jumpIndexMap[i + j]);
        }
        return jumpIndexMap[n - 1];
    }
*/