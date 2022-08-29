class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0, m = secondList.size(), n = firstList.size();
        while(i<n && j<m)
        {
            int st =  max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if(st <= end)
            {
                ans.push_back({st, end});
            }
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return ans;
    }
};