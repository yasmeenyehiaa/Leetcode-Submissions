class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ans;
        for(auto a: intervals)
        {
            if(a[0] <= end)
            {
                end = max(end, a[1]);
            }
            else 
            {
                ans.push_back({start, end});
                start = a[0], end = a[1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};