class type{
    public:
    int diff;
    int row;
    int col;
};

class compare{
    public:
    bool operator()(type &a, type &b){
        return a.diff > b.diff;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>>dist(r,vector<int>(c,1e9));
        priority_queue<type,vector<type>,compare>pq;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        pq.push(type{0,0,0});
        dist[0][0] = 0;
        while(!pq.empty()){
            int row = pq.top().row;
            int col = pq.top().col;
            int diff = pq.top().diff;
            if(row == r-1 && col == c-1) return diff;
            pq.pop();
            for(int i=0; i<4; i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >= 0 && nrow < r && ncol >= 0 && ncol< c){
                    int ele  = abs(heights[row][col] - heights[nrow][ncol]);
                    ele = max(ele,diff);
                    if(ele < dist[nrow][ncol]){
                        dist[nrow][ncol] = ele;
                        pq.push({ele,nrow,ncol});
                    }
                }
            }
        }
        return -1;
    }
};