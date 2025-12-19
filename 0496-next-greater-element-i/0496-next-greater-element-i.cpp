class Solution {
private:
    bool elementExistsInHMap(int num, unordered_map<int, int>& nums1HMap){
        return nums1HMap.find(num)!=nums1HMap.end();
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1HMap;
        vector<int> result;
        for(int num: nums1){
            nums1HMap[num] = -1;
        }
        stack<int> nextGreaterEleStk;
        for(int currNum: nums2){
            int stkSize = nextGreaterEleStk.size();
            if(stkSize>0){
                int topNum = nextGreaterEleStk.top();
                while(topNum < currNum){
                    if(elementExistsInHMap(topNum, nums1HMap)){
                        nums1HMap[topNum] = currNum;
                    }
                    nextGreaterEleStk.pop();
                    if(nextGreaterEleStk.size()==0) 
                        break;
                    else
                        topNum = nextGreaterEleStk.top();
                }   
            } 
            nextGreaterEleStk.push(currNum);
        }

        for(int num: nums1){
            result.push_back(nums1HMap[num]);
        }
        return result;
    }
};