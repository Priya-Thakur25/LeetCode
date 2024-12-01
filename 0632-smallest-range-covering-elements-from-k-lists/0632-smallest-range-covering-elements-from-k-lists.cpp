class Merge{
    public:
    int data;
    int row;
    int col;
};
class compare{
    public:
    bool operator()(Merge a, Merge b){
        return a.data > b.data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Merge, vector<Merge>, compare>pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i][0], i, 0});
            maxi = max(maxi,nums[i][0]);
            mini = min(mini,nums[i][0]);
        }

        int ansstart = mini;
        int ansend = maxi;
        while(!pq.empty()){
            int topval = pq.top().data;
            int toprow = pq.top().row;
            int topcol = pq.top().col;
            mini = topval;

            if(maxi-mini < ansend-ansstart){
                ansend = maxi;
                ansstart = mini;
            }

            pq.pop();
            if(topcol+1 < nums[toprow].size()){
                pq.push({nums[toprow][topcol+1], toprow, topcol+1});
            }
            else break;
            if(nums[toprow][topcol+1] > maxi) maxi = nums[toprow][topcol + 1];
        }

        return {ansstart,ansend};

    }
};