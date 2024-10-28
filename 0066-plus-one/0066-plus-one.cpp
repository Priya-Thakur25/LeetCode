class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i=n-1; i>=0; i--){
            if(digits[i] < 9){
                digits[i] += 1;
                carry = 0;
                break;
            }
            else if(digits[i] == 9 && carry == 1){
                digits[i] = 0;
                carry = 1;
            }
        }
        if(carry == 1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};