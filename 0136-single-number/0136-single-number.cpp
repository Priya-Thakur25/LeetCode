class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mapping;
        for(auto it:nums){
            mapping[it]++;
        }

        for(auto tr:mapping){
            if(tr.second == 1){
                return tr.first;
            }
        }
        return 0;
    }
};