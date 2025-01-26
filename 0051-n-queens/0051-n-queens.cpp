class Solution {
public:
unordered_map<int,bool>row;
unordered_map<int,bool>uD;
unordered_map<int,bool>lD;


void store(vector<vector<char>>&board, vector<vector<string>>&final){
    vector<string>tempans;
    for(auto i: board){
    string temp="";
        for(auto j: i){
            temp.push_back(j);
        }
        tempans.push_back(temp);
    }

    final.push_back(tempans);
}
void solve(int c, int n, vector<vector<char>>&board, vector<vector<string>>&final){
    if(c == n){
        store(board, final);
        return;
    }

    for(int i=0; i<n; i++){
        if(row[i] == false && uD[c-i] == false && lD[i+c] == false){
            row[i] = true;
            uD[c-i] = true;
            lD[i+c] = true;
            board[i][c] = 'Q';
            solve(c+1, n, board, final);
            board[i][c] = '.';
            row[i] = false;
            uD[c-i] = false;
            lD[i+c] = false;
        }
    }

}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n, vector<char>(n, '.'));
        vector<vector<string>>final;
        solve(0, n, board, final);
        return final;
    }
};