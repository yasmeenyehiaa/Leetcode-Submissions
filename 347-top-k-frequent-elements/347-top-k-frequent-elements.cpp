class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        
        for(auto p: freq)
        {
            pq.push({p.second, p.first});
        }
        
        while(ans.size() < k)
        {
            pair<int,int> p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        
        return ans;
        
    }
};