class Solution {
public:
    int findClosestNumber(vector<int>& A) {
        int N = A.size();
        sort(A.begin(), A.end());
        int prevdiff = abs(A[0] - 0), currdiff = 0, val = A[0];
        for (int i = 1; i < N; i++) {
            currdiff = abs(A[i] - 0);
            if (prevdiff >= currdiff){
                val = A[i];
                prevdiff = currdiff;
            }
        }
        return val;
    }
};