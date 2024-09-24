class Solution {
public:
void call(vector<char>&s, int len, int i){
    if(i >= len){
        return;
    }

    swap(s[i],s[len]);
    call(s,len-1,i+1);
    return;
}
    void reverseString(vector<char>& s) {
        int len = s.size();
        int i = 0;
        call(s,len-1,i);
    }
};