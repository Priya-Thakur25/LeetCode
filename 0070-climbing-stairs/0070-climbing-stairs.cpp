class Solution {
public:
    int solveUsingMem(vector<int>&dp, int n){
        if(n == 1 || n == 2 || n == 3) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solveUsingMem(dp,n-1) + solveUsingMem(dp,n-2);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solveUsingMem(dp,n);
    }
};