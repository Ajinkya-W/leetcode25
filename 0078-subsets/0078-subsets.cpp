class Solution {
    // Time Complexity: O(N * 2^N)
    // Space Complexity: O(N)

private:
    void backtrack(vector<int>& nums, vector<int> &path, int start, vector<vector<int>> &powerSet){
        powerSet.push_back(path);
        for(int j = start; j < nums.size(); j++){
            path.push_back(nums[j]);
            backtrack(nums, path, j+1, powerSet);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> path;
        backtrack(nums, path, 0, powerSet);

        return powerSet;
    }
};