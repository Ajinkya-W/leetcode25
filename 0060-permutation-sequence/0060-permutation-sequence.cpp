class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        int counter = 1;
        for (int i = 0; i < n; i++) {
            nums[i] = counter++;
        }

        while (k > 1) {
            k--;
            nextPermutation(nums);
        }
        string kthPermutation = "";
        for (int num : nums) {
            kthPermutation += to_string(num);
        }
        return kthPermutation;
    }
    void nextPermutation(vector<int>& nums) {

        int n = nums.size(), i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i])
                j--;

            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};