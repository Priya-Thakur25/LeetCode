class Graph {
public:
    unordered_map<int, vector<int>> adjList;

    void insertEdge(int u, int v) { adjList[u].push_back(v); }
};

void topo(int src, vector<int>& ans, unordered_map<int, vector<int>>& adjList) {
    unordered_map<int, int> indegree;
    for (auto i : adjList)
        indegree[i.first] = 0;
    for (auto i : adjList) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (auto i : indegree) {
        if (indegree[i.first] == 0)
            q.push(i.first);
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto nbr : adjList[front]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }
}
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        Graph g;
        for (auto i : p) {
            g.insertEdge(i[1], i[0]);
        }
        for(int i=0; i<numCourses; i++) g.adjList[i];
        vector<int> ans;
        topo(0, ans, g.adjList);
        if(ans.size() != numCourses) return {};
        return ans;
    }
};