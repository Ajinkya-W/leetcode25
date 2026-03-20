class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, leftMax = INT_MIN,
            rightMax = INT_MIN, totalWater = 0;
        while (left <= right) {

            if (leftMax <= rightMax) {
                leftMax = max(height[left], leftMax);
                totalWater += leftMax - height[left++];
            } else {
                rightMax = max(height[right], rightMax);
                totalWater += rightMax - height[right--];
            }
        }
        return totalWater;
    }
};