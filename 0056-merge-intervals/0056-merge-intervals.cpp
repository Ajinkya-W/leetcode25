class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        if(n == 0) return {};
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> nonOverlapIntervals;
    
        int start = intervals[0][0], end = intervals[0][1];
        for(int i  = 1; i < n; i++){
            if(end >= intervals[i][0]){
                end = max(end, intervals[i][1]);
            } else {
                nonOverlapIntervals.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        } 
        nonOverlapIntervals.push_back({start, end});
        return nonOverlapIntervals;
    }
};