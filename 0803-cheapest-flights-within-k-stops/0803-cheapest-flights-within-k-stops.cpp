class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adjList;
        // for(int i=0; i<n; i++){
        //     adjList[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        // }

        for(auto i: flights){
            adjList[i[0]].push_back({i[1],i[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src] = 0;
        while(!q.empty()){
            auto front = q.front();
            int stops = front.first;
            int desti = front.second.first;
            int distance = front.second.second;
            q.pop();

            if(stops > k) continue;
            for(auto nbr: adjList[desti]){
                if(distance + nbr.second < dist[nbr.first]){
                    dist[nbr.first] = distance + nbr.second;
                    q.push({stops+1,{nbr.first,dist[nbr.first]}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};