class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    void DFS(int row, int col, vector<vector<bool>>&visited, vector<vector<char>>&board){
        visited[row][col] = 1;
        for(int i=0; i<4; i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if(nrow >=0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() && !visited[nrow][ncol] && board[nrow][ncol] == 'O'){
                DFS(nrow,ncol,visited,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        //start-row
        for(int i=0; i<n; i++){
            if(!visited[0][i] && board[0][i] == 'O') DFS(0,i,visited,board);
        }
        //end-row
        for(int i=0; i<n; i++){
            if(!visited[m-1][i] && board[m-1][i] == 'O') DFS(m-1,i,visited,board);
        }
        //first-col
        for(int i=0; i<m; i++){
            if(!visited[i][0] && board[i][0] == 'O') DFS(i,0,visited,board);
        }
        //last-col
        for(int i=0; i<m; i++){
            if(!visited[i][n-1] && board[i][n-1] == 'O') DFS(i,n-1,visited,board);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){ board[i][j] = 'X';}
            }
        }
    }
};