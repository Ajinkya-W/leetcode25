class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, minElement = 5001, minIndex;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= nums[low]){
                minElement = minElement > nums[low]? nums[low]: minElement;
                low = mid + 1;
            } else{
                minElement = minElement > nums[mid]? nums[mid]: minElement;
                high = mid - 1;
            }
        }
        return minElement;
    }
};