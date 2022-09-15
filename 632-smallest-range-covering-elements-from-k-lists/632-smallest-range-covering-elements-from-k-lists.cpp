class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
          return x.first > y.first;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>,  vector<pair<int, pair<int, int>>>, cmp> pq;
        int mn = INT_MAX, mx = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            pq.push({nums[i][0], {i,0}});
            mn = min(mn, nums[i][0]);
            mx = max(mx, nums[i][0]);
        }
        int curMax = mx;
        while(pq.size() == nums.size())
        {
            auto tmp = pq.top();
            pq.pop();
            if(mx-mn > curMax-tmp.first)
            {
                mx = curMax;
                mn = tmp.first;
            }
            tmp.second.second++;
            if(nums[tmp.second.first].size() > tmp.second.second)
            {
                tmp.first = nums[tmp.second.first][tmp.second.second];
                pq.push(tmp);
                curMax = max(curMax, tmp.first);
            }
        }
        return {mn, mx};
    }
};