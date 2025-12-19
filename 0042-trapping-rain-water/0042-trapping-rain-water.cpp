class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0, volume = 0;
        while (left <= right) {
            if(height[left] < height[right]){
                if(height[left] > leftMax) // as vol update be 0 in this case
                    leftMax = height[left];
                else
                    volume += leftMax - height[left];
                left++;
            } else{
                if(height[right] > rightMax)
                    rightMax = height[right];
                else
                    volume += rightMax - height[right];
                right--;
            } 
        }
        return volume;
    }
};
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if(n == 0) return 0;
//         int left = 0, right = n - 1;
//         int leftMax = 0, rightMax = 0, volume = 0;
//         while (left <= right) {
//             if(height[left] > leftMax){
//                 leftMax = height[left];
//             }
//             if(height[right] > rightMax){
//                 rightMax = height[right];
//             }

//             if(leftMax<rightMax){
//                 volume += leftMax - height[left];
//                 left++;
//             }
//             else{
//                 volume += rightMax - height[right];
//                 right--;
//             }
//         }
//         return volume;
//     }
// };