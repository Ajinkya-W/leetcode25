class Solution {
    void backtrack(vector<int>& candidates, int start, int target, vector<int> &currentCombination, vector<vector<int>> &combination){
        if(target == 0){
            combination.push_back(currentCombination);
            return;
        }
        if(target < 0)
            return;
        
        for (int i = start; i < candidates.size(); i++) {
            
            currentCombination.push_back(candidates[i]);
            backtrack(candidates, i, target - candidates[i], currentCombination, combination);
            currentCombination.pop_back();
            
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combination;
        int start = 0;
        vector<int> currentCombination;
        backtrack(candidates, start, target, currentCombination, combination);
        return combination;
    }
};