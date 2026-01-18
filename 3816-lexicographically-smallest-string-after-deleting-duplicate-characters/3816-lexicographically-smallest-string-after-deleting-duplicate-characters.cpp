class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        // remaining[i] = count of character ('a' + i) remaining to be processed
        int remaining[26] = {0};
        // inResult[i] = count of character ('a' + i) currently in result
        int inResult[26] = {0};
        // Count total occurrences of each character
        for (char c : s)
            remaining[c - 'a']++;
        
        string result;
        
        for (char currentChar : s) {
            int currentIdx = currentChar - 'a';
            remaining[currentIdx]--;
            
            // Try to remove larger characters from result if:
            // 1. They are greater than current character
            // 2. Either they appear again later OR we have duplicates of them in result
            while (!result.empty()) {
                char lastChar = result.back();
                int lastIdx = lastChar - 'a';
                
                if (lastChar > currentChar && (remaining[lastIdx] > 0 || inResult[lastIdx] > 1)) {
                    inResult[lastIdx]--;
                    result.pop_back();
                } else {
                    break;
                }
            }
            
            result += currentChar;
            inResult[currentIdx]++;
        }
        
        // Remove duplicates from the end
        while (!result.empty() && inResult[result.back() - 'a'] > 1) {
            inResult[result.back() - 'a']--;
            result.pop_back();
        }
        
        return result;
    }
};