class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int ans=0, mini = prices[0];
         int n = prices.size();
         for(int i=0; i<n; i++){
            if(prices[i] < mini) mini=prices[i];
            int sub = prices[i] - mini;
            ans = max(ans,sub);
         }
         return ans;
    }
};