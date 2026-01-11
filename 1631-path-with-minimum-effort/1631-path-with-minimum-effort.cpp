class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // phase 1: setup implicit graph
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> efforts(row, vector<int>(col, INT_MAX));

        efforts[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});

        // phase 2: Dijstra loop

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();
            int e = top.first, r = top.second.first, c = top.second.second;
            pq.pop();

            if (r == row - 1 && c == col - 1){
                return efforts[r][c];
            }
            
            if (e > efforts[r][c])
                continue;

            for (int i = 0; i < 4; i++) {
                int newRow = r + dr[i];
                int newCol = c + dc[i];
                if (newRow >= 0 && newRow < row && newCol >= 0 &&
                    newCol < col) {
                    int newEffort =
                        max(e, abs(heights[newRow][newCol] - heights[r][c]));
                    if (newEffort < efforts[newRow][newCol]) {
                        pq.push({newEffort, {newRow, newCol}});
                        efforts[newRow][newCol] = newEffort;
                    }
                }
            }
        }

        // phae 3: return effort last index
        return efforts[row - 1][col - 1];
    }
};