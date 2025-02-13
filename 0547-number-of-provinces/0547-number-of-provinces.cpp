class Solution {
public:
    void solveUsingDFS(int& src, map<int,bool>&visited, vector<vector<int>>&isConnected){
        int col = isConnected.size();
        int row = src;
        visited[src] = true;
        for(int i=0; i<col; i++){
            if(row != i && isConnected[row][i] == 1){
                if(!visited[i]) solveUsingDFS(i, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        map<int,bool>visited;
        int src = 0;
        int row = isConnected.size();
        int count = 0;
        for(int i=0; i<row; i++){
            if(!visited[i]){
                count++;
                solveUsingDFS(i, visited, isConnected);
            }
        }
        return count;
    }
};