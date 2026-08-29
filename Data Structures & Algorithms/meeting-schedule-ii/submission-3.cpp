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

    static bool customComp(Interval &a, Interval &b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0)return 0;
        priority_queue<int,vector<int>,greater<int>> minh;
        sort(intervals.begin(),intervals.end(),customComp);
        int ans=1;
        for(int i=0;i<intervals.size();i++){
            if(minh.empty())minh.push(intervals[i].end);
            else if(intervals[i].start<minh.top()){
                ans++;
                minh.push(intervals[i].end);
            }
            else{
                minh.pop();
                minh.push(intervals[i].end);
            }
        } 
        return minh.size();
    }
};
