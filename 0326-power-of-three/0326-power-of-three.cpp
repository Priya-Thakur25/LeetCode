class Solution {
public:
   bool checkPower(int n){
    if(n == 1 || n == 3) return true;
    if(n%3 != 0 || n == 0) return false;

    if(n%3 == 0){
        n = n/3;
    }
    return checkPower(n);
}
    bool isPowerOfThree(int n) {
        if(checkPower(n)) return true;
        else return false;  
    }
};