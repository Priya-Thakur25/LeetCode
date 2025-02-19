class Graph{
    public:
    unordered_map<int,vector<int>>adjList;
    void insertEdge(int u, int v, int direc){ adjList[u].push_back(v);}
};
class Solution {
public:
    void solveusingbfs(int src, vector<int>&ans, unordered_map<int,vector<int>>&adj){
        unordered_map<int,int>indegree;
        for(auto i: adj) indegree[i.first] = 0;
        for(auto i: adj){
            for(auto j: i.second){
                indegree[j]++;
            }
        }

        queue<int>q;
        for(auto i: adj){
            if(indegree[i.first] == 0) q.push(i.first);
        }

        while(!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();
            for(auto nbr: adj[front]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        Graph g;
        for(auto i: p){
            g.insertEdge(i[1], i[0], 1);
        }
        vector<int>ans;
        solveusingbfs(0,ans,g.adjList);
        return (ans.size() == g.adjList.size());
    }
};