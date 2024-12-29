class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int>st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        int x = 0, cnt = 0, maxi=INT_MIN;
        for(auto it: st){
            if(st.find(it-1) == st.end()){
                x = it;
                cnt = 1;
            }
            while(st.find(x+1) != st.end()){
                x = x+1;
                cnt = cnt+1;
            }
            maxi = max(cnt, maxi);
        }
        return maxi;
    }
};