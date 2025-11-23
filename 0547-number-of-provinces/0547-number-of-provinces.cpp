class Solution {
private:
    void dfsHelper(vector<vector<int>>& isConnected, vector<bool>& visited, int currNode){
        if(visited[currNode]){
            return;
        }
        visited[currNode] = 1;
        int neighbours = isConnected[currNode].size();
        for(int j = 0; j < neighbours; j++){
            if(!visited[j] && isConnected[currNode][j]){
                dfsHelper(isConnected, visited, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int rows = isConnected.size(), totalProvinces = 0;
        vector<bool> visited(rows, 0);
        for(int currNode = 0; currNode < rows; currNode++){
            if(!visited[currNode]){
                totalProvinces++;
                dfsHelper(isConnected, visited, currNode);
            }
        }
        return totalProvinces;
    }
};