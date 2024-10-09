class Solution {
public:

    int minAddToMakeValid(string s) {
        stack<char>st;
        int len = s.length();
        int i = 0;
        while(len--){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else if(!st.empty() && st.top() == '(' && ch == ')'){
                st.pop();
            }
            else if(!st.empty() && st.top() == '{' && ch == '}'){
                st.pop();
            }
            else if(!st.empty() && st.top() == '[' && ch == ']'){
                st.pop();
            }
            else{
                st.push(ch);
            }
            i++;
        }
        int ans = st.size();
        return ans;
    }
};