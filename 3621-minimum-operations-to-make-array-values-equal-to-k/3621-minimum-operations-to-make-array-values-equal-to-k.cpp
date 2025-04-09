class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>setting;
        for(auto it: nums){
            setting.insert(it);
        }
        int count = 0;
        for(auto it: setting){
            if(it < k) return -1;
            if(it != k) count++;
        }
        return count;
    }
};