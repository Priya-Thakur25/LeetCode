class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0, count = 0;
        if(n == 1) return 1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                count = 2;
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                for(int k=0; k<n; k++){
                    if(k != j && k != i){
                        int dx_ = points[k][0] - points[i][0];
                        int dy_ = points[k][1] - points[i][1];

                        if(dy*dx_ == dx*dy_){
                            count++;
                        }
                    }
                }
                result = max(result, count);
            }
        }
        return result;
    }
};