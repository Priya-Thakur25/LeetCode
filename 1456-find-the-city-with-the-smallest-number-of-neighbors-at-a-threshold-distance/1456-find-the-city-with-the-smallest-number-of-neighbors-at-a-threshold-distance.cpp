class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& e, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(auto i: e){
            dist[i[0]][i[1]] = i[2];
            dist[i[1]][i[0]] = i[2];
        }
        for(int i=0; i<n; i++) dist[i][i] = 0;
        for(int h=0; h<n; h++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][h] == 1e9 || dist[h][j] == 1e9) continue;
                    dist[i][j] = min(dist[i][j], dist[i][h] + dist[h][j]);
                }
            }
        }

        int count = n;
        int city = -1;
        for(int i=0; i<n; i++){
            int now = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold) now++;
            }
            if(count >= now){
                count = now;
                city = i;
            }
        }
        return city;
    }
}; 