class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int left = 0, right = n-1, leftBoundary = 0, rightBoundary = 0;
        int totalWater = 0;

        while(left <= right){
            if(leftBoundary <= rightBoundary){
                leftBoundary = max(leftBoundary, height[left]);
                
                totalWater += leftBoundary - height[left++];
            } else{
                rightBoundary = max(rightBoundary, height[right]);
                
                totalWater += rightBoundary - height[right--];
            }   
        }
        return totalWater;
    }
};
