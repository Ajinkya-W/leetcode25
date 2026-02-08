class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numEntries;
        for (int num : nums)
            numEntries.insert(num);

        int longestSequence = 0;
        for (int num : numEntries) {
            int sequence = 0;
            if (numEntries.count(num - 1) == 0) {
                while (numEntries.count(num) == 1) {
                    num++;
                    sequence++;
                }
            }
            longestSequence = max(longestSequence, sequence);
        }
        return longestSequence;
    }
};