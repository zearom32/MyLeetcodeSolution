/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int state = 0;
        vector<Interval> ans;
        for (int i = 0; i != intervals.size(); i++){
            Interval& a = intervals[i];
            switch (state)
            {
            case 0:
                if (a.end < newInterval.start){
                    ans.push_back(a);
                }
                else
                {
                    if (newInterval.end < a.start){
                        ans.push_back(newInterval);
                        ans.push_back(a);
                        state = 2;
                    }
                    else
                        if (a.start <= newInterval.start && a.end >= newInterval.end){
                            ans.push_back(a);
                            state = 2;
                        }
                        else
                        {
                            if (newInterval.start < a.start){
                                ans.push_back(a);
                                ans.back().start = newInterval.start;
                                state = 1;
                            }
                            else
                            {
                                ans.push_back(a);
                                state = 1;
                            }
                        }
                }
                break;
            case 1:
                if (newInterval.end < a.start){
                    ans.back().end = max(ans.back().end, newInterval.end);
                    state = 2;
                    ans.push_back(a);
                }
                else
                {
                    ans.back().end = a.end;
                }
                break;
            case 2:
                ans.push_back(a);
                break;
            }
        }
        if (state == 0){
            ans.push_back(newInterval);
        }
        else
            if (state == 1){
                ans.back().end = max(ans.back().end, newInterval.end);
            }
        return ans;
    }
};