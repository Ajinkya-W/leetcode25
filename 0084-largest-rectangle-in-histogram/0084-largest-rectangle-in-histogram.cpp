class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        vector<int> stk;
        stk.reserve(n);

        for(int i = 0; i <= n; i++){
            int currBarHeight = i<n? heights[i]: 0;
            while(!stk.empty() && heights[stk.back()] > currBarHeight){
                int candidateHeight = heights[stk.back()];
                stk.pop_back();

                int leftBoundary = stk.empty()? -1: stk.back();
                int rightBoundary = i;
                int candidateWidth = rightBoundary - leftBoundary - 1;

                maxArea = max(maxArea, candidateWidth * candidateHeight);
            }
            stk.push_back(i);
        }
        return maxArea;
    }
};