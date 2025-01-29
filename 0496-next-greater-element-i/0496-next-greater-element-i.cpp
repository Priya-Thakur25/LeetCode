class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>mapping;
        vector<int>temp(n,-1);
        vector<int>ans;
        stack<int>st;
        int i=n-1;

        for(int j=0; j<n; j++){
            mapping[nums2[j]] = j;
        }
        while(i >= 0){
            int ele = nums2[i];
            if(st.empty()) st.push(ele);
            else if(!st.empty() && ele > st.top()){
                while(!st.empty() && st.top() < ele){
                    st.pop();
                }
                if(!st.empty()) temp[i] = st.top();
                st.push(ele);
            }
            else{
                temp[i] = st.top();
                st.push(ele);
            }
            i--;
        }

        for(int j=0; j<nums1.size(); j++){
            int ele = nums1[j];
            int index = mapping[ele];
            ans.push_back(temp[index]);
        }
        return ans;
    }
};