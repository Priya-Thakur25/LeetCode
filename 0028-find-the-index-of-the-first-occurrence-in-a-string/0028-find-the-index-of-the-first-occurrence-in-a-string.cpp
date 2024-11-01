class Solution {
public:
    int strStr(string s1, string s2) {
        int i=0,n1 = s1.length();
        int j=0,n2 = s2.length();
        int flag = 0;
        for(i=0; i<n1; i++){
            flag = 0;
            for(j=0; j<n2; j++){
                if(s1[i+j] != s2[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                return i;
            }
        }
        return -1;
    }
};