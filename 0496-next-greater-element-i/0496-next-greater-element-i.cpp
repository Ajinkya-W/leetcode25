class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1HMap;
        vector<int> result;
        for(int num: nums1){
            nums1HMap[num] = -1;
        }
        stack<int> nextGreaterEleStk;
        for(int currNum: nums2){
            while(nextGreaterEleStk.size()>0 && nextGreaterEleStk.top() < currNum){
                if(nums1HMap.find(nextGreaterEleStk.top())!=nums1HMap.end()){
                    nums1HMap[nextGreaterEleStk.top()] = currNum;
                }
                nextGreaterEleStk.pop();  
            } 
            nextGreaterEleStk.push(currNum);
        }

        for(int num: nums1){
            result.push_back(nums1HMap[num]);
        }
        return result;
    }
};