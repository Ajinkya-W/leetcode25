class Solution {
private:
    int binarySearchHelper(vector<int>&nums, int low, int high, int target){
        int mid = low + (high - low) / 2;
        if(low == high && target!= nums[mid]){
            return -1;
        }
        while(low <= high){
            mid = low + (high - low)/2;
            if(target==nums[mid]){
                return mid;
            }
            if(nums[low] <= nums[mid]){
                if(target>=nums[low] && target<nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            } else {
                if(target>nums[mid] && target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        return binarySearchHelper(nums, low, high, target);
    }
};