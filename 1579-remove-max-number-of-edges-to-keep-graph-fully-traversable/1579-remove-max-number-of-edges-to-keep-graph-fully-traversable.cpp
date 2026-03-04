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
        if(parent[x] == x)
            return x;
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
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DSU alice(n+1);
        DSU bob(n+1);

        int usedEdges = 0;

        // type 3 first
        for(auto &edge: edges){

            if(edge[0] == 3){

                int u = edge[1], v = edge[2];

                if(alice.unionBySize(u,v)){
                    bob.unionBySize(u,v);
                    usedEdges++;
                }
            }
        }

        // Alice & bob edges
        for(auto &edge: edges){
            if(edge[0] == 1){
                if(alice.unionBySize(edge[1],edge[2]))
                    usedEdges++;
            }
            if(edge[0] == 2){
                if(bob.unionBySize(edge[1],edge[2]))
                    usedEdges++;
            }
        }

        // verify connectivity
        if(alice.getSize(1) != n || bob.getSize(1) != n)
            return -1;

        return edges.size() - usedEdges;
    }
};