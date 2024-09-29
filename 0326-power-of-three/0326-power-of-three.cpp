class Solution {
public:
   bool checkPower(int n){
    if(n == 1 || n == 3) return true;
    if(n%3 != 0 || n == 0) return false;

   
    return checkPower(n/3);
}
    bool isPowerOfThree(int n) {
        if(checkPower(n)) return true;
        else return false;  
    }
};