class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        int maxArea = 0;
        stack<int> stk;
        // Iterate to n to include a virtual '0' height sentinel
        for(int i = 0; i <= n; i++){
            // Virtual sentinel height of 0 at index n forces stack cleanup
            int currHeight = (i == n)? 0: heights[i];

            while(!stk.empty() && heights[stk.top()] > currHeight){
                int currBarHeight = heights[stk.top()];
                stk.pop();
                
                // If stack is empty, it means the popped bar was the smallest seen so far
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