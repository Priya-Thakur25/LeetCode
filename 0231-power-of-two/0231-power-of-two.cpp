class Solution {
public:
bool checkPower(int n){
    if(n == 1 || n == 2) return true;
    if(n%2 != 0 || n == 0) return false;

    if(n%2 == 0){
        n = n/2;
    }
    return checkPower(n);
}
    bool isPowerOfTwo(int n) {
        if(checkPower(n)) return true;
        else return false;
    }
};