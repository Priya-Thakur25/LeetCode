class DisjointSet{
    public:
    vector<int>rank,parent;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void UnionFind(int u, int v){
        int up_u = findParent(u);
        int up_v = findParent(v);

        if(up_u == up_v) return;
        if(rank[up_u] > rank[up_v]) parent[up_v] = up_u;
        else if(rank[up_u] < rank[up_v]) parent[up_u] = up_v;
        else{
            parent[up_u] = up_v;
            rank[up_v]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        int n = stones.size();
        for(auto it: stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        DisjointSet d(maxrow+maxcol+1);
        unordered_map<int,int>stonesRemoval;
        for(auto  i:stones){
            int rowNode = i[0];
            int colNode = i[1] + maxrow + 1;
            if(d.findParent(rowNode) != d.findParent(colNode)){
                d.UnionFind(rowNode, colNode);
            }
            stonesRemoval[rowNode] = 1;
            stonesRemoval[colNode] = 1;
        }

        int count = 0;
        for(auto i: stonesRemoval){
            if(d.findParent(i.first) == i.first) count++;
        }

        return n-count;
    }
};