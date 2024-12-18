class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int start = 0, end = height.size()-1;
        while(start < end){
            int currArea = (end - start) * min(height[end], height[start]);
            if(height[end] > height[start])
                start++;
            else
                end--;
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};