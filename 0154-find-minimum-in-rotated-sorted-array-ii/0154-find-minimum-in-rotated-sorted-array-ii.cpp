class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, minElement = nums[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            minElement = min(minElement, nums[mid]);

            if (nums[mid] < nums[high]) {
                high = mid - 1;
            } else if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high--;
            }
        }
        return minElement;
    }
};