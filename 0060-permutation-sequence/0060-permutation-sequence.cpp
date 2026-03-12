class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> nums;
        vector<int> fact(n);
        string ans = "";

        // 1. build numbers [1..n]
        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        // 2. compute factorials
        fact[0] = 1;
        for (int i = 1; i < n; i++)
            fact[i] = fact[i - 1] * i;

        k--; // convert to 0-index

        // 7. repeat until all digits chosen
        for (int i = n; i >= 1; i--) {
            // 4. index = k / (remaining-1)!
            int idx = k / fact[i - 1];

            // 5. append numbers[index] and remove it
            ans += to_string(nums[idx]);

            nums.erase(nums.begin() + idx);

            // 6. update k = k % (remaining-1)!
            k %= fact[i - 1];
        }

        return ans;
    }
};