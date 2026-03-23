class Solution {
public:
    bool rec(int i, int k, vector<int>& stones, unordered_map<int, int>& pos, vector<vector<int>>& dp) {
        if (i == stones.size() - 1) return true;
        
        if (dp[i][k] != -1) return dp[i][k];

        for (int jump = k - 1; jump <= k + 1; jump++) {
            if (jump <= 0) continue;

            int nextPos = stones[i] + jump;

            if (pos.count(nextPos)) {
                if (rec(pos[nextPos], jump, stones, pos, dp)) {
                    return dp[i][k] = 1;
                }
            }
        }

        return dp[i][k] = 0;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
            pos[stones[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return rec(0, 0, stones, pos, dp);
    }
};