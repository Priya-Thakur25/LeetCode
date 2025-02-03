class Solution {
public:
    int romanToInt(string s) {
        int i=0;
        int n = s.length();
        int ans = 0;
        while(i < n){
            char ch = s[i];
            if(i+1 <n && ch == 'I' && s[i+1] == 'V'){
                ans = ans + 4;
                i++;
            }
            else if(i+1 <n && ch == 'I' && s[i+1] == 'X'){
                ans = ans + 9;
                i++;
            }
            else if(i+1 <n && ch == 'X' && s[i+1] == 'L'){
                ans = ans + 40;
                i++;
            }
            else if(i+1 <n && ch == 'X' && s[i+1] == 'C'){
                ans = ans + 90;
                i++;
            }
            else if(i+1 <n && ch == 'C' && s[i+1] == 'D'){
                ans = ans + 400;
                i++;
            }
            else if(i+1 <n && ch == 'C' && s[i+1] == 'M'){
                ans = ans + 900;
                i++;
            }
            else if(ch == 'I') ans = ans + 1;
            else if(ch == 'V') ans = ans + 5;
            else if(ch == 'X') ans = ans + 10;
            else if(ch == 'L') ans = ans + 50;
            else if(ch == 'C') ans = ans + 100;
            else if(ch == 'D') ans = ans + 500;
            else if(ch == 'M') ans = ans + 1000;
            i++;
        }
        return ans;
    }
};