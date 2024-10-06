class Solution {
public:
int coinRec(vector<int>& coins, int amount){
    if(amount == 0) return 0;

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int recans = 0;
        if((amount - coins[i]) >= 0){
            recans = coinRec(coins, amount-coins[i]);
            if(recans != INT_MAX){
                int ans = 1 + recans;
                 mini = min(mini,ans);
            }
        }
    }
    return mini;
}

int coinMemo(vector<int>& coins, int amount, vector<int>&dp){
    if(amount == 0) return 0;

    if(dp[amount] != -1) return dp[amount];
    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int recans = 0;
        if((amount - coins[i]) >= 0){
            recans = coinMemo(coins, amount-coins[i], dp);
            if(recans != INT_MAX){
                int ans = 1 + recans;
                 mini = min(mini,ans);
            }
        }
    }
    dp[amount] = mini;
    return dp[amount];
}
    int coinChange(vector<int>& coins, int amount) {
        // int ans = coinRec(coins, amount);
        // if(ans != INT_MAX){
        // return ans;
        // }
        // else return -1;

        int n = amount;
        vector<int>dp(n+1,-1);
        int ans =  coinMemo(coins, amount, dp);
        if(ans != INT_MAX){
        return ans;
        }
        else return -1;

    }
};