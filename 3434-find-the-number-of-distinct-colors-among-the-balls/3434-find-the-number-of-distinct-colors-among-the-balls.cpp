class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_color; // Stores the color of each ball
        unordered_map<int, int> color_count; // Tracks how many balls have each color
        unordered_set<int> distinct_colors; // Tracks the number of distinct colors
        vector<int> result;

        for (auto& query : queries) {
            int ball = query[0], new_color = query[1];

            if (ball_color.find(ball) != ball_color.end()) {
                int old_color = ball_color[ball];

                if (--color_count[old_color] == 0) { // If no ball uses old_color, remove it
                    distinct_colors.erase(old_color);
                }
            }

            ball_color[ball] = new_color;
            color_count[new_color]++;
            distinct_colors.insert(new_color);

            result.push_back(distinct_colors.size());
        }

        return result;
    }
};
