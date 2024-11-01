class Solution {
public:
    void reverseString(vector<char>& s) {
        int n =  s.size();
        int i=0, j=n-1;
        for(i=0,j=n-1; i<j; i++,j--){
            swap(s[i], s[j]);
        }
    }
};