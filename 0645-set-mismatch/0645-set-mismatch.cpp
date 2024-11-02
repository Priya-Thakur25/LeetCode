class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int>setting(nums.begin(), nums.end());
        int dupli = 0, i = 0 , n = nums.size();
        vector<int>ans; 
        for(i=0; i<n-1; i++){
           if(nums[i] == nums[i+1]){
            ans.push_back(nums[i]);
            break;
           }
        }
        i=0;
        for(auto sett: setting){
            if(i+1 != sett){
                ans.push_back(i+1);
                break;
            }
            i++;
        }
        if(ans.size() != 2){
            ans.push_back(nums.size());
        }
        return ans;
    }
};