class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, minElement = 5001, minIndex;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // sorted
            if (nums[mid] < nums[high]) {
                if (minElement > nums[mid]) {
                    minElement = nums[mid];
                }
                high = mid - 1;
            } else {
                if (minElement > nums[low]) {
                    minElement = nums[low];
                }
                low = mid + 1;
            }
        }
        return minElement;
    }
};