class Solution {
public:
   bool checkPower(int n){
    if(n == 1 || n == 4) return true;
    if(n%4 != 0 || n == 0) return false; 
    return checkPower(n/4);
}
    bool isPowerOfFour(int n) {
        if(checkPower(n)) return true;
        else return false;  
    }
};