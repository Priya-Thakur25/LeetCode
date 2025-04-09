class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0, mini = INT_MAX;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            if(prices[i] < mini){
                mini = prices[i]; 
                maxi = prices[i];
            }
            else if(prices[i] > maxi){
                maxi = prices[i];
            }

            ans = max(ans,maxi-mini);
        }
        return ans;
    }
};