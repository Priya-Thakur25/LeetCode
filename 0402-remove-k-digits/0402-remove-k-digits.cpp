class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        int n = num.length();
        for(int i=0; i<n; i++){
            int digit = num[i] - '0';
            while(!st.empty() && k > 0 && st.top() > digit){
                st.pop();
                k--;
            }
            if(!st.empty() || digit != 0){
                st.push(digit);
            }
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string s = "";
        while(!st.empty()){
            int digit = st.top();
            st.pop();
            s += digit + '0';
        }

        reverse(s.begin(), s.end());
        return s == ""? "0" : s;
    }
};