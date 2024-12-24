class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0], maxi=INT_MIN;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < mini) mini = prices[i];
            int sub = prices[i] - mini;
            maxi = max(maxi, sub);
        }
        return maxi;
    }
};