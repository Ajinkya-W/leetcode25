class Solution {
private:
    void dfsColourFill(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int color, int ogColor){
        if((sr>=0 && sr<image.size()) && (sc>=0 && sc<image[0].size()) && visited[sr][sc]==0){
            visited[sr][sc] = 1;
            if(image[sr][sc]==ogColor){
                image[sr][sc] = color;
                dfsColourFill(image, visited, sr+1, sc, color, ogColor);
                dfsColourFill(image, visited, sr-1, sc, color, ogColor);
                dfsColourFill(image, visited, sr, sc-1, color, ogColor);
                dfsColourFill(image, visited, sr, sc+1, color, ogColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool> (image[0].size(), 0));
        int ogColor = image[sr][sc];
        dfsColourFill(image, visited, sr, sc, color, ogColor);
        return image;
    }
};