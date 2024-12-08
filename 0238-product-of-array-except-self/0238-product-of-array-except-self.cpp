class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preProd(nums.size()), postProd(nums.size());
        preProd[0] = 1, postProd[nums.size()-1] = 1;
        for(int i=0; i<nums.size()-1;i++){
            preProd[i+1] = nums[i] * preProd[i];
        }
        for(int i=nums.size()-1; i>=1;i--){
            postProd[i-1] = postProd[i] * nums[i];
        }
        for(int i=0; i<nums.size();i++){
            preProd[i] = preProd[i] * postProd[i];
        }
        return preProd;
    }
};