/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool customComparison(const Interval &a, const Interval &b){
        if(a.start == b.start)return a.end<b.end;
        return a.start<b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(),intervals.end(),customComparison);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i-1].end>intervals[i].start)return false;
        }
        return true;
    }
};
