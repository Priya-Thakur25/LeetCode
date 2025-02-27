class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adjList;
        for(auto i: times){
            adjList[i[0]].push_back({i[1],i[2]});
        }

        queue<pair<int,int>>q;
        q.push({0,k});
        vector<int>time(n+1,1e9);
        time[k] = 0;
        while(!q.empty()){
            auto front  = q.front();
            int timeTill = front.first;
            int desti = front.second;
            q.pop();
            for(auto nbr: adjList[desti]){
                if(nbr.second + timeTill < time[nbr.first]){
                    time[nbr.first] = nbr.second + timeTill;
                    q.push({time[nbr.first],nbr.first});
                }
            }
        }

        int maxi = INT_MIN;
        for(int i=1; i<=n;  i++){
            if(time[i] == 1e9) return -1;
            else maxi = max(maxi,time[i]);
        }
        return maxi;
    }
};