class Solution {
public:
    bool rec(int csi, int pj, vector<int>& stones, unordered_map<int, int>& seen, vector<vector<int>> &dp) {
        if (csi == stones.size() - 1)
            return dp[csi][pj] = 1;
        if (dp[csi][pj] != -1) 
            return dp[csi][pj];
        int cs = stones[csi];
        bool result = false;

        for(int nextJump = pj - 1; nextJump <= pj + 1; nextJump++){
            int nextPos = cs + nextJump;
            
            if(nextJump > 0 && seen.count(nextPos)){
                int nextIdx = seen[nextPos];
                if(dp[nextIdx][nextJump] == -1){
                    dp[nextIdx][nextJump] = rec(nextIdx, nextJump, stones, seen, dp);
                }
                result = result || dp[nextIdx][nextJump];
                if(result) break;
            }
        }
        return dp[csi][pj] = result;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> seen;
        int n = stones.size();
        for (int i = 0; i < n; i++)
            seen[stones[i]] = i; 
        
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return rec(0, 0, stones, seen, dp);
    }
};