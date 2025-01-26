class Solution {
public:
bool isSafe(int r, int c, char ch, vector<vector<char>>&board){
    for(int i=0; i<board.size(); i++) if(board[r][i] == ch) return false;
    for(int i=0; i<board.size(); i++) if(board[i][c] == ch) return false;
    for(int i=0; i<board.size(); i++){
        if(board[(3*(r/3)) + i/3][(3*(c/3)) + i%3] == ch) return false;
    }
    return true;
}
bool solve(vector<vector<char>>&board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board.size(); j++){
            if(board[i][j] == '.'){
                for(char ch='1'; ch<='9'; ch++){
                    if(isSafe(i, j, ch, board)){
                        board[i][j] = ch;
                        bool ans = solve(board);
                        if(ans) return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};