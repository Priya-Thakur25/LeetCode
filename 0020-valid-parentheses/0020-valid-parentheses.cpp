class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        int i=0, n=s.length();

        while(i < n){
            char ch = s[i];
            if(!st.empty() && st.top() == '(' && ch == ')') st.pop();
            else if(!st.empty() && st.top() == '[' && ch == ']') st.pop();
            else if(!st.empty() && st.top() == '{' && ch == '}') st.pop();
            else st.push(ch);
            i++;
        }
        return st.empty();
    }
};