class Solution {
private:
    int maxProductHelper(vector<int>& nums){
        int prod=nums[0], maxProd=max(INT_MIN,nums[0]), maxNum =nums[0];
        for(int i=1; i< nums.size(); i++){
            if(prod == 0)
                prod = nums[i];
            else
                prod*= nums[i]; 
            maxProd = max(prod,maxProd);
            maxNum = max(maxNum, nums[i]);
        }
        prod = nums[nums.size()-1];
        for(int i=nums.size()-2; i>=0; i--){
            if(prod == 0)
                prod = nums[i]; 
            else
                prod*= nums[i]; 
            maxProd = max(prod,maxProd);
        }
        
        return max(maxProd, maxNum);
    }
public:
    int maxProduct(vector<int>& nums) {
        int maxPositiveProduct, maxNegativeProduct;
        return maxProductHelper(nums);
    }
};