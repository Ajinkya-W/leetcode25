class Solution {
    // This is our 'Check' function (O(N + k))
    // bool canZero(int k, vector<int>& nums, vector<vector<int>>& queries) {
    //     int n = nums.size();
    //     // Use long long because sum of k (10^4) over many queries can exceed INT_MAX
    //     vector<long long> diff(n + 2, 0);

    //     // Apply first k queries to the difference array
    //     for (int i = 0; i < k; ++i) {
    //         int l = queries[i][0], r = queries[i][1], val = queries[i][2];
    //         diff[l] += val;
    //         diff[r + 1] -= val;
    //     }

    //     // Verify if prefix sum at each index >= nums[i]
    //     long long current_reduction = 0;
    //     for (int i = 0; i < n; ++i) {
    //         current_reduction += diff[i];
    //         if (current_reduction < nums[i]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
public:
    // int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    //     int low = 0;
    //     int high = queries.size();
    //     int ans = -1;

    //     // Binary Search on the number of queries (k)
    //     while (low <= high) {
    //         int mid = low + (high - low) / 2;
    //         if (canZero(mid, nums, queries)) {
    //             ans = mid;
    //             high = mid - 1; // Try to find a smaller k
    //         } else {
    //             low = mid + 1;
    //         }
    //     }
    //     return ans;
    // }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int Q = queries.size();
        
        // Safety buffer of n+2 handles r+1 without bounds checks
        vector<long long> diff(n + 2, 0);
        long long currCapacityToZero = 0;
        int j = 0; // Pointer to the next query to activate

        for (int i = 0; i < n; ++i) {
            // Step 1: Incorporate differences that start or end at this index
            // This includes queries activated in previous iterations
            currCapacityToZero += diff[i];

            // Step 2: If the current "power" is less than the student's value,
            // activate the next queries in the list until the student hits zero.
            while (currCapacityToZero < nums[i]) {
                if (j == Q) return -1; // No more queries left to satisfy this student

                int l = queries[j][0], r = queries[j][1], val = queries[j][2];
                
                // Only add to the immediate reduction power if the query covers index i
                if (l <= i && r >= i) {
                    currCapacityToZero += val;
                }
                
                // Mark the boundaries in the difference array for future indices
                diff[l] += val;
                diff[r + 1] -= val;
                
                // Move to the next query in the list
                j++; 
            }
        }
        
        return j; // The count of queries activated
    }
};