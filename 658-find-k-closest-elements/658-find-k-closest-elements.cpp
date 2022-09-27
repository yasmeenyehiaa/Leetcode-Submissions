class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        
        for(auto a: arr)
        {
            if(pq.size() < k) pq.push({abs(x-a), a});
            else if(abs(x-a) < pq.top().first)
            {
                pq.push({abs(x-a), a});
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};