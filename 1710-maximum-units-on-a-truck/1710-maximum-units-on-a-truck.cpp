class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {        
        int ans = 0;
        priority_queue<pair<int,int>> pq;
        
        for(auto p: boxTypes)
        {
            pq.push({p[1], p[0]});
        }
        
        while(truckSize > 0 && !pq.empty())
        {
            int u = pq.top().first , b = pq.top().second;
            pq.pop();
            if(truckSize >= b)
            {
                ans += u*b;
                truckSize -= b;
            }
            else 
            {
                ans += u*truckSize;
                break;
            }
        }
        return ans;
    }
};