class Solution {
public:
double findAns(double x, int n, double &ans){
    if(n <= 0) return 1;
    ans = findAns(x,n/2,ans);
    if(n%2 == 0){
        ans = ans * ans;
    }
    else{
        ans = ans * ans * x;
    }
    return ans;
}
    double myPow(double x, int n) {
        double ans = 1;
        if(x == 1) return 1;
        if(x == -1) return (n%2 == 0)? 1 : -1;
        if(n < 0){
            if(n == INT_MIN){
                n = -(n+1);
                return 1/findAns(x,n,ans);
            }
            else return 1/findAns(x,0-n,ans);
        }
        return findAns(x,n, ans);
    }
};