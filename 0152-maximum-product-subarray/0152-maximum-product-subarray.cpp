class Solution {
private:
    int maxProductHelper(vector<int>& nums){
        int prod=1, maxProd=INT_MIN;
        for(int i=0; i< nums.size(); i++){
            prod = (prod == 0) ? nums[i] : prod * nums[i];
            maxProd = max(prod,maxProd);
        }
        prod = 1;
        for(int i=nums.size()-1; i>=0; i--){
            prod = (prod == 0) ? nums[i] : prod * nums[i];
            maxProd = max(prod,maxProd);
        }
        return maxProd;
    }
public:
    int maxProduct(vector<int>& nums) {
        int maxPositiveProduct, maxNegativeProduct;
        return maxProductHelper(nums);
    }
};