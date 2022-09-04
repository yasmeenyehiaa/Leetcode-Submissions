class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> endHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> startHeap;
        int n = intervals.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
           startHeap.push({intervals[i][0],i});
           endHeap.push({intervals[i][1],i});
        }
        
        for(int i=0; i<intervals.size(); i++)
        {   
            int j = endHeap.top().second, ed = endHeap.top().first, val = -1;
            endHeap.pop();
            while(!startHeap.empty() && startHeap.top().first < ed) 
            {
                startHeap.pop();
            }
            if(!startHeap.empty()) val = startHeap.top().second;
            ans[j] = val;
        }
       return ans;
    }
};