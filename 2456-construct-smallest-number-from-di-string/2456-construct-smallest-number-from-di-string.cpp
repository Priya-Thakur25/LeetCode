class Solution {
public:
    void solve(string& pattern, string & ans){
        int count = 0;
        stack<int>st;
        for(int i=0; i<=pattern.length(); i++){
            count++;
            st.push(count);
            while(!st.empty() && pattern[i] == 'I'){
                ans.push_back(st.top()+'0');
                st.pop();
            }
        }

        while(!st.empty()){
            ans.push_back(st.top() + '0');
            st.pop();
        }
    }
    string smallestNumber(string pattern) {
        string ans = "";
        solve(pattern,ans);
        return ans;
    }
};