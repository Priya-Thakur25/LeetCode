class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int i=0;
        int sum = 0;
        while(i < n){
            char ch = s[i];
            if(i+1 != n && ch == 'I' && s[i+1] == 'V'){
                sum += 4; i+=2; continue;
            }
            else if(i+1 != n && ch == 'I' && s[i+1] == 'X'){
                sum += 9; i+=2; continue;
            }
            else if(i+1 != n && ch == 'X' && s[i+1] == 'L'){
                sum += 40; i+=2; continue;
            }
            else if(i+1 != n && ch == 'X' && s[i+1] == 'C'){
                sum += 90; i+=2; continue;
            }
            else if(i+1 != n && ch == 'C' && s[i+1] == 'D'){
                sum += 400; i+=2; continue;
            }
            else if(i+1 != n && ch == 'C' && s[i+1] == 'M'){
                sum += 900; i+=2; continue;
            }
            else if(ch == 'I')sum += 1;
            else if(ch == 'V') sum += 5;
            else if(ch == 'X') sum += 10;
            else if(ch == 'L') sum += 50;
            else if(ch == 'C') sum += 100;
            else if(ch == 'D') sum += 500;
            else if(ch == 'M') sum += 1000;
            i++;
        }
        return sum;
    }
};