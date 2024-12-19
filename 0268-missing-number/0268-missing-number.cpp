class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] != i){
        //         return i;
        //     }
        // }
        // return nums.size();
        int i=0, n =nums.size();
        while(i<n){
            if(nums[i]==i || nums[i]==n) i++;
            else{
                int temp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = temp;
            }
        }
        for(i=0;i<n;i++){
            if(nums[i]!=i) return i;
        }
        return n;
    }
};