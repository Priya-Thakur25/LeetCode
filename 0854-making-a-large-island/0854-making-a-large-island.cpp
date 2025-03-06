class Disjoint{
    public:
    vector<int>parent,size;
    
    Disjoint(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    
    void UnionFind(int u, int v){
        int up_u = findParent(u);
        int up_v = findParent(v);
        
        if(up_u == up_v) return;
        if(size[up_u] > size[up_v]){ 
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
        else{
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint d(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int  it=0; it<4; it++){
                    int nrow = i + dr[it]; 
                    int ncol = j + dc[it];
                    if(nrow >= 0  && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        int node = i*n + j;
                        int newnode = nrow*n + ncol;
                        d.UnionFind(node,newnode);
                    }
                }
            }
        }
        int maxsum = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                set<int>setting;
                for(int  it=0; it<4; it++){
                    int nrow = i + dr[it]; 
                    int ncol = j + dc[it];
                    if(nrow >= 0  && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        int newnode = nrow*n + ncol;
                        setting.insert(d.findParent(newnode));
                    }
                }
                int S = 1;
                for(auto st: setting){
                    S += d.size[st];
                }
                maxsum = max(maxsum,S);
            }
        }
        return maxsum == 0? n*n: maxsum;
    }
};