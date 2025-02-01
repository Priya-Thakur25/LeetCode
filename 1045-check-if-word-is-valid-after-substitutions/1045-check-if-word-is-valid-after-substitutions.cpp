class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        int i = 0;
        stack<char>st;
        while(i < n){
            char ch = s[i];
            if(!st.empty() && ch == 'c' && st.top() == 'b'){
                st.pop();
                if(!st.empty() && st.top() == 'a') st.pop();
                else return false;
            }
            else st.push(ch);
            i++;
        }
        return st.empty();
    }
};