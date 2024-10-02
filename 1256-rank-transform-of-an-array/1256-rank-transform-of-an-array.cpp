class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans;
        vector<int>temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        set<int>setting;
        for(auto k: temp){
            setting.insert(k);
        }
        int index = 1;
        unordered_map<int,int>mapping;
        for(auto i: setting){
            mapping[i] = index;
            index++;
        }

        int j=0;
        while(j < arr.size()){
            auto it = mapping.find(arr[j]);
            ans.push_back(it->second);
            j++;
        }

        return ans;
    }
};