class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i = 0;
        while(i < s.length()){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else if(!st.empty() && ((st.top() == '(' && ch == ')') || (st.top() == '{' && ch == '}') || (st.top() == '[' && ch == ']'))){
                st.pop();
            }
            else{
                return false;
            }
            i++;
        }
        if(st.empty()) return true;
        else return false;
    }
};