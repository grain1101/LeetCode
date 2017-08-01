struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool cmp(const Interval& a, const Interval& b) {
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        int idx = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= intervals[idx].end && intervals[i].end > intervals[idx].end)
                intervals[idx].end = intervals[i].end;
            else if (intervals[i].start > intervals[idx].end) intervals[++idx] = intervals[i];
        }
        intervals.resize(idx + 1);
        return intervals;
    }
};