class Solution {
public:
int solvingRecursion(int n){
    if(n == 0 || n == 1){
        return n;
    }

    int ans = solvingRecursion(n-1) + solvingRecursion(n-2);
    return ans;
}
    int fib(int n) {
        int ans = solvingRecursion(n);
        return ans;
    }
};