class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1HMap;
        int size = nums1.size();
        nums1HMap.reserve(size);
        vector<int> result(size);
        for(int num: nums1){
            nums1HMap[num] = -1;
        }
        stack<int> candidateValues;
        for(int currNum: nums2){
            while(candidateValues.size()>0 && candidateValues.top() < currNum){
                auto it = nums1HMap.find(candidateValues.top());
                if (it != nums1HMap.end()) {
                    it->second = currNum;
                }
                candidateValues.pop();  
            } 
            candidateValues.push(currNum);
        }

        for(int itr = 0; itr < nums1.size(); itr++){
            int num = nums1[itr];
            result[itr] = nums1HMap[num];
        }
        return result;
    }
};