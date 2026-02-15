class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> length(n, 1);
        vector<int> count(n, 1);

        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    }
                    else if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }

            maxLen = max(maxLen, length[i]);
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (length[i] == maxLen)
                total += count[i];
        }

        return total;
    }
};