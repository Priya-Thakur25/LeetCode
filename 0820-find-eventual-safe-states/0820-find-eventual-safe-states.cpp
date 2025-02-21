class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adjrev;
        unordered_map<int,int>indegree;
        for(int i=0; i<graph.size(); i++) indegree[i] = 0;
        for(int i=0; i<graph.size(); i++){
            for(auto  it: graph[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int>q;
        vector<int>ans;
        for(auto i: indegree){
            if(i.second == 0) q.push(i.first);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr: adjrev[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};