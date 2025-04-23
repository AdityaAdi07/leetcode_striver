class Solution {
public:
    static bool compareSecond(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), compareSecond);

        int count = 1;
        int last = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= last) {
                count++;
                last = intervals[i][1];
            }
        }

        return intervals.size() - count;
    }
};
