class Solution {
public:
    void backtrack(int open, int close, int n, string curr, vector<string>& result) {
        
        if (curr.size() == 2 * n) {
            result.push_back(curr);
            return;
        }

        if (open < n)
            backtrack(open + 1, close, n, curr + "(", result);

        if (close < open)
            backtrack(open, close + 1, n, curr + ")", result);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, n, "", result);
        return result;
    }
};