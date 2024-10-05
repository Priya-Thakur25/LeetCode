class Solution {
public:
int solvingRecursion(int n){
    if(n == 0 || n == 1){
        return n;
    }

    int ans = solvingRecursion(n-1) + solvingRecursion(n-2);
    return ans;
}
int solvingMemo(int n, vector<int>&dp){
    if(n == 0 || n ==  1){
        dp[n] = n;
        return n;
    }
    if(dp[n] != -1) return dp[n];
    dp[n] = solvingMemo(n-1, dp) + solvingMemo(n-2, dp);
    return dp[n];
}
    int fib(int n) {
        // int ans = solvingRecursion(n);
        // return ans;

        vector<int>dp(n+1, -1);
        solvingMemo(n,dp);
        return dp[n];
    }
};