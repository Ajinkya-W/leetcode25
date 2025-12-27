class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& currentSet, int start, vector<vector<int>>& powerSet){
        powerSet.push_back(currentSet);
        for(int i = start; i < nums.size(); i++){
            // THE PRUNING: Skips redundant branches
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }
            currentSet.push_back(nums[i]);
            backtrack(nums, currentSet, i+1, powerSet);
            currentSet.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> currentSet;
        sort(nums.begin(), nums.end());
        backtrack(nums, currentSet, 0, powerSet);
        return powerSet;
    }
};