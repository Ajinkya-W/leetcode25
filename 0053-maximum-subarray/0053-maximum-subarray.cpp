class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, n = nums.size();
        int windowSum = 0;
        for(int i  = 0; i < n; i++){
            windowSum += nums[i];
    
            maxSum = max(maxSum, windowSum);
            if(windowSum < 0)
                windowSum = 0;
        }
        return maxSum;
    }
};
/*
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, n = nums.size();
        for(int i  = 0; i < n; i++){
            int windowSum = 0;
            for(int j = i; j < n; j++){
                windowSum += nums[j];
                maxSum = max(maxSum, windowSum);
            }
        }
        return maxSum;
    }
*/