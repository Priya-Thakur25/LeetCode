class type{
    public:
    int row;
    int col;
    int dist;
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<type>q;
        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<vector<int>>ans(m, vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j,0});
                    visited[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            auto front = q.front();
            int row = front.row;
            int col = front.col;
            int dist = front.dist;
            ans[row][col] = dist;
            q.pop();
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
            for(int  i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    if(!visited[nrow][ncol]){
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol,dist+1});
                    }
                }
            }
        }
        return ans;
    }
};