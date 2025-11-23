class Solution {
private:
    int rottingBfs(vector<vector<int>>& grid, int& freshOranges, queue<pair<int, int>>& q){
        int timeElapsed = 0;
        int dr[4] = {0, -1, 0, 1}, dc[4] = {1, 0, -1, 0};
        while(!q.empty()){
            bool didRottingHappen = 0;
            int qSize = q.size();
            for(int i=0; i < qSize; i++){
                int row = q.front().first;
                int col = q.front().second;
                for(int i=0; i<4; i++){
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
                    if((newRow>=0 && newRow<grid.size()) && (newCol>=0 && newCol<grid[0].size()) && grid[newRow][newCol]==1){
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        freshOranges--;
                        didRottingHappen = true;
                    }
                } 
                q.pop();
            }
            if(didRottingHappen){
                timeElapsed++;
            }
        }
        return timeElapsed;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int totalTimeElapsed = 0, freshOranges = 0;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                if(grid[row][col]==2){
                    q.push({row, col});
                } else if(grid[row][col]==1){
                    freshOranges++;
                }
            }
        }
        totalTimeElapsed = rottingBfs(grid, freshOranges, q);
        if(freshOranges>0)
            return -1;
        return totalTimeElapsed;
    }
};