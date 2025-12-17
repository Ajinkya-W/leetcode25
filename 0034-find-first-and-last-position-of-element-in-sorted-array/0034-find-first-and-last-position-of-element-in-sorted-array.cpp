class Solution {
private:
    int getFirstOccurence(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1; // Corrected boundary
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1; // Look left for earlier occurrence
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int getLastOccurence(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1; // Corrected boundary
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1; // Look right for later occurrence
            } else if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = getFirstOccurence(nums, target);
        // Optimization: if 'first' is -1, 'last' will also be -1
        if (first == -1) return {-1, -1};
        
        int last = getLastOccurence(nums, target);
        return {first, last};
    }
};