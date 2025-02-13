class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();
        q.push({sr, sc});
        int val = image[sr][sc];
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            int row = ele.first;
            int col = ele.second;
            if(image[row][col] == 1 || image[row][col] == val)
            image[row][col] = color;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if (image[nrow][ncol] == val && image[nrow][ncol] != color) {
                        image[nrow][ncol] = color;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return image;
    }
};