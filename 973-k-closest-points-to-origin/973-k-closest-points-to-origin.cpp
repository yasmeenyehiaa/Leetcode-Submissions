class Solution {
public:
    float dist(int x, int y)
    {
        return sqrt(x*x + y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
        
        priority_queue<pair<float, pair<int,int>>> pq;
        
        for(int i=0; i<points.size(); i++)
        {
            pq.push({-dist(points[i][0],points[i][1]), {points[i][0],points[i][1]}});
        }
        
        int x = 0;
        while(x++ < k)
        {
            vector<int> v;
            v.push_back(pq.top().second.first);
            v.push_back(pq.top().second.second);
            pq.pop();
            ans.push_back(v);
        }        
        return ans;
    }
};