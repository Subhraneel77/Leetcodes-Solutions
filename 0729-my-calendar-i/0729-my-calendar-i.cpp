class MyCalendar {
    map<int, int> intervals; // Stores intervals with start as key and end as value
public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto next = intervals.lower_bound(start); // Find next interval
        if (next != intervals.end() && next->first < end) {
            return false; // Overlaps with next interval
        }
        if (next != intervals.begin() && prev(next)->second > start) {
            return false; // Overlaps with previous interval
        }
        intervals[start] = end; // No overlap, add interval
        return true;
    }
};
