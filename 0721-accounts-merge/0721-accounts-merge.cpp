class DisjointSet{
    public:
    vector<int>rank,parent;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void UnionFind(int u, int v){
        int up_u = findParent(u);
        int up_v = findParent(v);

        if(up_u == up_v) return;
        if(rank[up_u] > rank[up_v]) parent[up_v] = up_u;
        else if(rank[up_u] < rank[up_v]) parent[up_u] = up_v;
        else{
            parent[up_u] = up_v;
            rank[up_v]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet d(n);
        unordered_map<string,int>mp;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else{
                    d.UnionFind(i,mp[accounts[i][j]]);
                }
            }
        }

        unordered_map<int,vector<string>>mails;
        for(auto it: mp){
            string email = it.first;
            int parent = d.findParent(it.second);
            mails[parent].push_back(email);
        }

        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            vector<string>temp2 = mails[i];
            sort(temp2.begin(), temp2.end());
            temp.insert(temp.end(),temp2.begin(), temp2.end());
            if(temp.size() > 1)ans.push_back(temp);
        }

        return ans;
    }
};