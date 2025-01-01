class Solution {
public:
unordered_map<int,bool>rowCheck;
unordered_map<int,bool>LowDiag;
unordered_map<int,bool>UpDiag;

bool isSafe(vector<vector<char>>&board, int col, int row){
    if(rowCheck[row] == true) return false;
    if(LowDiag[row+col] == true) return false;
    if(UpDiag[col-row] == true) return false;
    return true;
}


void store(vector<vector<string>>&ans, vector<vector<char>>&board){
    vector<string>temp;
    string s = "";
    int n = board.size();
    for(int i=0; i<n; i++){
        s = "";
        for(int j=0; j<n; j++){
            s.push_back(board[i][j]);
        }
        temp.push_back(s);
    }
    ans.push_back(temp);
}
void solve(vector<vector<string>>&ans, vector<vector<char>>&board, int col, int n){
    if(col >= n){
        store(ans,board);
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe(board,col,row)){
            board[row][col] = 'Q';
            rowCheck[row] = true;
            LowDiag[row+col] = true;
            UpDiag[col-row] = true;

            solve(ans, board, col+1, n);

            board[row][col] = '.';
            rowCheck[row] = false;
            LowDiag[row+col] = false;
            UpDiag[col-row] = false;
        }
    }
}

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        int col = 0;
        solve(ans, board, col, n);
        return ans;
    }
};