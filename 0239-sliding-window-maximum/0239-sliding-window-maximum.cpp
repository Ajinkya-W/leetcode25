class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; // Stores indices
        vector<int> result;
        result.reserve(n - k + 1);

        for(int i = 0; i < n; i++) {
            // 1. Maintain Monotonicity (Decreasing)
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            } 
            dq.push_back(i);
            
            // 2. Remove indices that are out of the window
            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            // 3. Store result once the first window is complete
            if(i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};