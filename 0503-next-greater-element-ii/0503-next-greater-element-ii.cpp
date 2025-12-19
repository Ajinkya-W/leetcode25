class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> candidateIndices;
        for(int i = 0; i < 2*n; i++){
            int currNum = nums[i % n];
            while(!candidateIndices.empty() && nums[candidateIndices.top()] < currNum){
                result[candidateIndices.top()] = currNum;
                candidateIndices.pop();  
            } 
            if(i < n)
                candidateIndices.push(i);
        }
        return result;
    }
};
