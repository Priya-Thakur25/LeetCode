class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        
        // Create events: start of an interval is +1, end of an interval is -1
        for (const auto& interval : intervals) {
            events.emplace_back(interval[0], 1);    // Starting event
            events.emplace_back(interval[1] + 1, -1); // Ending event
        }
        
        // Sort events by time. In case of a tie, ending event (-1) comes before starting event (+1)
        sort(events.begin(), events.end());
        
        int active = 0, maxGroups = 0;
        
        // Process all events
        for (const auto& event : events) {
            active += event.second;
            maxGroups = max(maxGroups, active); // Track the max number of active intervals
        }
        
        return maxGroups;
    }
};
