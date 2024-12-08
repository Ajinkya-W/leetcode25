class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hmap;
        for(int i=0; i<nums.size();i++){
            if(hmap[nums[i]]==1){
                return 1;
            }
            hmap[nums[i]] = 1;
        }
        return 0;
    }
};