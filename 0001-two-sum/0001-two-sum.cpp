class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_map<int, int> hmap;
        for(int i=0; i < nums.size(); i++){
            hmap[nums[i]] = i;
        }
        for(int i=0; i < nums.size(); i++){
            if(hmap.find(target-nums[i])!=hmap.end() && hmap[target-nums[i]]!=i){
                ans[0] = i;
                ans[1] = hmap[target-nums[i]];
                break;
            }
        }
        return ans;
    }
};