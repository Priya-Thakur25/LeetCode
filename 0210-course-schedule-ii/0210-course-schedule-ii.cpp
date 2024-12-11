class Graph{
    public:
    unordered_map<int,list<int>>adjList;
    
    void insert(int u, int v){
        adjList[u].push_back(v);
    }

    void topoOrder(vector<int>&Order){
        unordered_map<int,int>inDegree;
        queue<int>q;

        for(auto mp: adjList){
            inDegree[mp.first] = 0;
        }

        for(auto i:adjList){
            for(auto nbr: i.second){
                inDegree[nbr]++;
            }
        }

        for(auto i: adjList){
            if(inDegree[i.first] == 0){
                q.push(i.first);
            }
        }

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            Order.push_back(frontNode);
            for(auto nbr: adjList[frontNode]){
                inDegree[nbr]--;
                if(inDegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        Graph g;
        for(auto i: p){
            g.insert(i[1],i[0]);
        }

        for(int i=0; i<numCourses; i++){
            g.adjList[i];
        }
        
        vector<int>Order;
        g.topoOrder(Order);
        if(Order.size() != numCourses) return {};
        return Order;
    }
};