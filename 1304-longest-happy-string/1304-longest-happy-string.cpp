class compare{
    public:
    bool operator()(pair<char,int>&a, pair<char,int>&b){
        return a.second < b.second;
    }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char,int>, vector<pair<char,int>>, compare>pq;
        if(a != 0)pq.push({'a',a});
        if(b != 0)pq.push({'b',b});
        if(c != 0)pq.push({'c',c});

        string ans = "";
        while(pq.size() > 1){
            auto temp = pq.top();
            pq.pop();
            if(temp.second >= 2){
                ans.push_back(temp.first);
                ans.push_back(temp.first);
                temp.second -= 2;
            }
            else{
                ans.push_back(temp.first);
                temp.second -= 1;
            }

            if(!pq.empty()){
                auto tempo = pq.top();
                pq.pop();
                if(tempo.second >= 2 && tempo.second >= temp.second){
                    ans.push_back(tempo.first);
                    ans.push_back(tempo.first);
                    tempo.second -= 2;
                }
                else{
                    ans.push_back(tempo.first);
                    tempo.second -= 1;
                }
                if(tempo.second > 0) pq.push(tempo);
            }
            if(temp.second > 0) pq.push(temp);
        }

        if(!pq.empty()){
            auto temp = pq.top();
            if(temp.second == 1){
                ans.push_back(temp.first);
                temp.second--;
            }
            else if(temp.second >= 2){
                ans.push_back(temp.first);
                ans.push_back(temp.first);
                temp.second-=2;
            }
        }
        return ans;
    }
};