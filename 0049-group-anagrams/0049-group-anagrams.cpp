class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sizes = strs.size();
        int count = 0,i = 0;
        vector<string>temp;
        vector<vector<string>>ans;
        vector<pair<string,string>>pairing(sizes);
        while(i < sizes){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            pairing[i].second = strs[i];
            pairing[i].first = temp;i++;
        }
        sort(pairing.begin(), pairing.end());
        for(int i=0; i<sizes; i++){
           if(i == 0){
            temp.clear();
            temp.push_back(pairing[i].second);
           }
           else if(pairing[i].first != pairing[i-1].first){
            ans.push_back(temp);
            temp.clear();
            temp.push_back(pairing[i].second);
           }
           else if(pairing[i].first == pairing[i-1].first){
            temp.push_back(pairing[i].second);
           }
        }
        ans.push_back(temp);
        return ans;
    }
};