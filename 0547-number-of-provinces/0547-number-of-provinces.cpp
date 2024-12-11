class Solution {
public:
void solve(int& src, vector<vector<int>>& isConnected, int n, unordered_map<int,bool>&isVisited){
    isVisited[src] = 1;
    for(int i=0; i<n; i++){
        int nbr = i;
        if(src != nbr && isConnected[src][nbr] == 1){
            if(!isVisited[nbr]){
                solve(nbr, isConnected, n, isVisited);
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0, n = isConnected.size();
        unordered_map<int,bool>isVisited;
        for(int i=0; i<n; i++){
            if(!isVisited[i]){
                count++;
                solve(i, isConnected, n, isVisited);
            }
        }
        return count;
    }
};