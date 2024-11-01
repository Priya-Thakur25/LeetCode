class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();
        int i = 0;
        while(i < n){
            if(!st.empty() && s[i] == ')' && st.top() == '('){
                st.pop();
            }
            else if(!st.empty() && s[i] == ']' && st.top() == '['){
                st.pop();
            }
            else if(!st.empty() && s[i] == '}' && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        if(st.empty()) return true;
        else return false;
    }
};