class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int i=0,j=0;
        if(n2 > n1) return false;
        while(i != n1){
            if(str1[i] == 'z' && str2[j] == 'a'){
                j++;
            }
            else if(str1[i] == str2[j] ||  str1[i]+1 == str2[j]){
                j++;
            }
            i++;
            if(i == n1 && j != n2) return false;
        }
        return true;
    }
};