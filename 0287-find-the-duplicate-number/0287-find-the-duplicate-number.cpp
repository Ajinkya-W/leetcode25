class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0], tortoise = nums[0];
        while(1){
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
            if(hare == tortoise)
                break;
        }
        int ptr1 = tortoise;
        int ptr2 = nums[0];
        while(ptr1!=ptr2){
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};