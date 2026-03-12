class Solution {
    void rec(const vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            // duplicate pruning
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            curr.push_back(nums[i]);
            used[i] = 1;
            rec(nums, curr, ans, used);
            curr.pop_back();
            used[i] = 0;
        }
        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), 0);
        rec(nums, curr, ans, used);
        return ans;
    }
};