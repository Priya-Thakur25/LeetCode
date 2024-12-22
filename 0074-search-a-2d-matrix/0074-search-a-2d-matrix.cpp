class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int row = m.size();
        int col = m[0].size();
        int i=0,find = 0, finded = 0;
        // if(row == 1 && col == 1) return 0;
        for(i=0; i<row; i++){
            if(m[i][0] > target){
                find = i;
                break;
            }
        }

        for(int j=0; j<col; j++){
            if(i-1 >=0 && m[i-1][j] == target){
                finded = 1;
                break;
            }
        }
        if(finded) return true;
        return false;
    }
};