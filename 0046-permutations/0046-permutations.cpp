class Solution {
    void rec(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, vector<bool>& used){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){     
            int num = nums[i]; 
            if(used[i] == 0){
                curr.push_back(num);
                used[i] = 1;
                rec(nums, curr, ans, used);
                curr.pop_back();
                used[i] = 0;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        vector<bool> used(nums.size());
        rec(nums, curr, ans, used);
        return ans;
    }
};