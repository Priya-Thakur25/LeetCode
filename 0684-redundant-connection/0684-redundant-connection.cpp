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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int  n = edges.size();
        DisjointSet d(n);
        int u = 0; int v = 0;
        for(auto i: edges){
            if(d.findParent(i[0]) != d.findParent(i[1])){
                d.UnionFind(i[0], i[1]);
            }
            else{
                u = i[0]; v = i[1];
            }
        }
        return {u,v};
    }
};