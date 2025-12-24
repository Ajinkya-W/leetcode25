class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() || nums2.empty()){
            return {};
        }
        unordered_map<int, int> candidateMap;
        int n1 = nums1.size(), n2 = nums2.size();
        candidateMap.reserve(n1);

        // create map for candidates
        for(auto num: nums1){
            candidateMap[num] = -1;
        }


        stack<int> stk;
        for(int i = 0; i < n2; i++){
            int num = nums2[i];
            while(!stk.empty() && stk.top() < num){
                auto index = candidateMap.find(stk.top());
                if(index != candidateMap.end()){
                    index->second = num;
                }
                stk.pop();
            }
            stk.push(num);
        }

        vector<int> result;
        for(int i = 0; i < n1; i++){
            int num = nums1[i];
            result.push_back(candidateMap[num]);
        }
        return result;
    }
};