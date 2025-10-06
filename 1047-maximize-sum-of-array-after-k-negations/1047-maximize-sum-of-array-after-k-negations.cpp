class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        // Flip k smallest (or all negatives if less than k)
        for(int i=0; i<nums.size() && nums[i]<0 && k>0; i++){
            nums[i]*=-1;
            k=k-1;
        }
    
        // If k is still positive and odd, flip the smallest element
        if(k%2==1){
            sort(nums.begin(), nums.end());
            nums[0]*=-1;
        }
        
        // Sum all elements
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        return sum;
    }
};