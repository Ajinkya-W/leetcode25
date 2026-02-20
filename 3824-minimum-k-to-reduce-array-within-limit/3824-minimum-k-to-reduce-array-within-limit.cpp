class Solution {
public:
    int minimumK(vector<int>& nums) {
        int left = 1, right = 100000;
        int result = right;

        while(left <= right){
            int mid = left + (right - left) / 2;
            long long times = 0;
            long long target = (long long) mid * mid;

            for(int num: nums){
                times += (num + mid -1) / mid;
                if(times > target) break;
            }
            if(times <= target){
                result = mid;
                right = mid - 1;
            } else{
                left = mid +1;
            }
        }
        return result;
    }
};