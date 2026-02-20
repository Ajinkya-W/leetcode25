class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Use standard int for the boundaries based on the problem constraints (max sum 25 million)
        int low = *max_element(weights.begin(), weights.end());
        
        // Use 0 for the initial sum, as the max sum (25 million) fits in an int.
        int high = accumulate(weights.begin(), weights.end(), 0); 
        int ans = high; // Initialize ans to the upper bound
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // Mid is the capacity (C) we are checking
            
            // LOGIC FIX: Start the day count at 1, as the work must start on Day 1.
            int currD = 1; 
            
            // Use int for currentLoad as max load is bounded by max weight (500) and mid (25M).
            int currLoad = 0; 

            // Check function: Calculate total days needed (currD) for capacity 'mid'
            for (int weight : weights) {
                if ((currLoad + weight) <= mid) {
                    // Package FITS on the current trip. Load it up.
                    currLoad += weight;
                } else {
                    // Package DOESN'T FIT.
                    // 1. The current trip ends.
                    // 2. Start a new day.
                    currD++; 
                    // 3. This package is the first one loaded on the *new* day.
                    currLoad = weight; 
                }
            }
            
            // Binary Search Decision: If the required days (currD) is feasible (<= D)
            if (currD <= days) {
                // This capacity works. Store it as a potential answer and try for a smaller one.
                ans = mid;
                high = mid - 1; 
            } else {
                // This capacity is too small. Increase the capacity.
                low = mid + 1;
            }
        }
        return ans;
    }
};