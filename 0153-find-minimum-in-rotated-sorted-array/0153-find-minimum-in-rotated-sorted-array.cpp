class Solution {
private:
    int binarySearchHelper(vector<int> nums){
        int minTillNow = INT_MAX;
        int low = 0, high = nums.size() - 1, mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[low] <= nums[mid]){
                minTillNow = min(minTillNow, nums[low]);
                low = mid + 1;
            }
            else{
                minTillNow = min(minTillNow, nums[mid]);
                high = mid - 1;
            }
        }
        return minTillNow;
    }
public:
    int findMin(vector<int>& nums) {
        return binarySearchHelper(nums);
    }
};