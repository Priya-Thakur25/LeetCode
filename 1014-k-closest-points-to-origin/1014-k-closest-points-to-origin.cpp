class info{
    public:
    float val;
    int x;
    int y;
};

class compare{
    public:
    bool operator()(info a, info b){
        return a.val > b.val;
    }
};

float findSqrt(int a, int b){
    return sqrt((a*a)+(b*b));
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<info, vector<info>, compare>pq;
        for(auto po:points){
            float sq = findSqrt(po[0],po[1]);
            pq.push({sq,po[0],po[1]});
        }
        vector<vector<int>>ans;
        while(k--){
            if(!pq.empty()){
                ans.push_back({pq.top().x, pq.top().y});
                pq.pop();
            }
        }

        return ans;
    }
};