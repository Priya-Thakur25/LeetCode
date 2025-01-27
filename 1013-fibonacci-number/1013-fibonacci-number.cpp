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

//bottom-up approach
int solveUsingTab(int n, vector<int>&dp){
    if(n == 0) dp[0] = 0;
    if(n >= 1){
        dp[0] = 0;
        dp[1] = 1;
    }

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
    int fib(int n) {
        vector<int>dp(n+1,-1);
        // return solveUsingMem(n, dp);

        return solveUsingTab(n,dp);
    }
};