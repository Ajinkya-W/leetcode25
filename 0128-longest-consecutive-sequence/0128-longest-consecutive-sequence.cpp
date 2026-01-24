class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqueElements(nums.begin(), nums.end());

        int longestSequence = 0;
        for (int num : uniqueElements) {

            if (uniqueElements.find(num - 1) == uniqueElements.end()) {
                // leader: noone can reach till this guy by +1
                int currSequenceLength = 1;
                long long nextNum = num + 1;
                while (uniqueElements.count(nextNum)) {
                    currSequenceLength++;
                    nextNum++;
                }
                longestSequence = max(longestSequence, currSequenceLength);
            }
        }
        return longestSequence;
    }
};