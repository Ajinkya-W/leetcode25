class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> difference(nums.size()+1, 0);
        for(vector<int>& query: queries){
            int start = query[0], end = query[1]+1;
            difference[start]++;
            difference[end]--;
        }
        int currPrefixSum = 0;

        for(int i = 0; i < nums.size(); i++){
            currPrefixSum += difference[i];

            if(nums[i] - currPrefixSum > 0)
                return false;
        }
        return true;
    }
};