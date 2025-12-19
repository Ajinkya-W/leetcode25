class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> candidateIndices;
        for(int index = 0; index < 2 * n; index++){
            int currNum = nums[index % n];
            while(candidateIndices.size()>0 && nums[candidateIndices.top()] < currNum){
                if(result[candidateIndices.top() % n] == -1){
                    result[candidateIndices.top() % n] = currNum;
                }
                candidateIndices.pop();  
            } 
            if(index < n)
                candidateIndices.push(index);
        }
        return result;
    }
};
