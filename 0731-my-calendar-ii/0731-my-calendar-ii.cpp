class MyCalendarTwo {
public:
    // Store all intervals that are already booked once
    vector<pair<int, int>> bookings;
    // Store intervals that have been double booked
    vector<pair<int, int>> doubleBookings;
    
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        // Check for triple booking
        for (const auto& db : doubleBookings) {
            if (max(start, db.first) < min(end, db.second)) {
                // If there's overlap with a double booking, return false
                return false;
            }
        }
        
        // Check for overlap with existing bookings
        for (const auto& b : bookings) {
            int overlapStart = max(start, b.first);
            int overlapEnd = min(end, b.second);
            if (overlapStart < overlapEnd) {
                // If there's an overlap, add it to double bookings
                doubleBookings.push_back({overlapStart, overlapEnd});
            }
        }
        
        // Add the new booking as it doesn't cause triple booking
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
