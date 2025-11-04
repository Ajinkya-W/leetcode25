class Solution {
private:
    void dfsHelper(const vector<vector<int>> &isConnected, vector<bool> &visited, int curr){
        visited[curr] = 1;
        for(int next=0; next< isConnected[curr].size(); next++){
            if(isConnected[curr][next]==1 && !visited[next])
                dfsHelper(isConnected, visited, next);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces =0;
        vector<bool> visited(isConnected.size(), 0);
        for(int curr=0; curr<isConnected.size(); curr++){
            if(!visited[curr]){
                provinces++;
                dfsHelper(isConnected, visited, curr);
            }
        }
        return provinces;
    }
};