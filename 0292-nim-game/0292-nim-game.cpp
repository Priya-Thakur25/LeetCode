class Solution {
public:
    bool canWinNim(int n) {
    //     if(n <= 3) return true;
    //     int modi = 0;
    //     int divi = 0;
    //     modi = n%3;
    //     divi = n/3;
    //     if(divi%2 == 0){
    //         if(modi != 0) return true;
    //         else return false;
    //     }
    //     if(divi%2 != 0){
    //         if(modi != 0) return false;
    //         else return true;
    //     }

    //     return false;
    // }
    if(n%4 == 0) return false;
    return true;
    }
};