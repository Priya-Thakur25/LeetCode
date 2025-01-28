class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        map<int,int>mapping;
        vector<int>ans;
        for(auto i: nums){
            mapping[i]++;
        }

        for(auto i:mapping){
            pq.push({i.second,i.first});
        }

        while(k--){
            auto temp = pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }

        return ans;
    }
};