class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        stack<char>st;
        for(int i=0; i<n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                if(!st.empty()) st.pop();
            }
            else st.push(s[i]);
        }
        string ans = "";
        int n2 = st.size();
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};