class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findParent(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionFind(int u, int v) {
        int up_u = findParent(u);
        int up_v = findParent(v);
        if (up_u == up_v)
            return;

        if (rank[up_u] > rank[up_v])
            parent[up_v] = up_u;
        else if (rank[up_v] > rank[up_u])
            parent[up_u] = up_v;
        else {
            parent[up_u] = up_v;
            rank[up_v]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int free = 0;
        int commit = 0;
        DisjointSet d(n);

        for (auto i : connections) {
            if (d.findParent(i[0]) != d.findParent(i[1])) {
                d.unionFind(i[0], i[1]);
                commit++;
            } else
                free++;
        }

        int pc = n - commit - 1;
        return pc <= free ? pc : -1;
    }
};