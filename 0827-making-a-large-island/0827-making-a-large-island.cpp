class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    bool unionBySize(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return false;
        if (size[rootx] > size[rooty]) {
            size[rootx] += size[rooty];
            parent[rooty] = rootx;
        } else if (size[rootx] <= size[rooty]) {
            size[rooty] += size[rootx];
            parent[rootx] = rooty;
        }
        return true;
    }
    int getSize(int x) {
        int root = find(x);
        return size[root];
    }
};
class Solution {
private:
    vector<pair<int, int>> UnionDirections = {{0, 1}, {1, 0}},
                           checkDirections = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int currIndex = i * n + j;
                    for (int itr = 0; itr < 2; itr++) {
                        int newRow = i + UnionDirections[itr].first;
                        int newCol = j + UnionDirections[itr].second;
                        if (newRow >= 0 && newRow < n && newCol >= 0 &&
                            newCol < n && grid[newRow][newCol]) {
                            int nextIndex = newRow * n + newCol;
                            ds.unionBySize(currIndex, nextIndex);
                        }
                    }
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < n * n; i++)
            ans = max(ans, ds.getSize(i));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> roots;
                    int size = 1;

                    for (int itr = 0; itr < 4; itr++) {
                        int newRow = i + checkDirections[itr].first;
                        int newCol = j + checkDirections[itr].second;
                        if (newRow >= 0 && newCol >= 0 && newCol < n &&
                            newRow < n && grid[newRow][newCol] == 1) {
                            int root = ds.find(newRow * n + newCol);
                            if (roots.insert(root).second)
                                size += ds.getSize(root);
                        }
                    }
                    ans = max(ans, size);
                }
            }
        }
        return ans;
    }
};