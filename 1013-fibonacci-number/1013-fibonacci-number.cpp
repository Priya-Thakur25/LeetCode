class Solution {
public:
int solve(int n){
    if(n == 0 || n == 1) return n;
    int ans = solve(n-1) + solve(n-2);
    return ans;
}

//top-down approach
int solveUsingMem(int n, vector<int>&dp){
    if(n == 0 || n == 1) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2,dp);
    return dp[n];
}
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return solveUsingMem(n, dp);
    }
};