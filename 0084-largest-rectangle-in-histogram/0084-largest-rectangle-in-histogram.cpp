class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        int maxArea = 0;
        stack<int> stk;
        for(int i = 0; i <= n; i++){
            int currHeight = (i == n)? 0: heights[i];

            while(!stk.empty() && heights[stk.top()] > currHeight){
                int currBarHeight = heights[stk.top()];
                stk.pop();
                
                int leftBoundary = stk.empty() ? -1 : stk.top();
                int rightBoundary = i;
                int width = rightBoundary - leftBoundary - 1;

                maxArea = max(maxArea, currBarHeight * width);
            }
            stk.push(i);
        }
        return maxArea;
    }
};