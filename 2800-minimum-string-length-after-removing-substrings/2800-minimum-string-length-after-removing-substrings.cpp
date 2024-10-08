class Solution {
public:
    int minLength(string s) {
        stack<char>subst;
        int i=0;
        int size = s.length();
        for(i=0; i<size; i++){
            if((!subst.empty()) && (subst.top() == 'A') && (s[i] == 'B')){
                    subst.pop();
                }
            else if((!subst.empty()) && (subst.top() == 'C') && (s[i] == 'D')){
                    subst.pop();
                }
            else {
                subst.push(s[i]);
            }
        }
        return subst.size();
    }
};