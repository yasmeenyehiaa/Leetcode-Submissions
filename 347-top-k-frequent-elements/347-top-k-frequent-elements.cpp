class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        
        vector<vector<int>> bucket(n+1);
        for(auto p: freq)
        {
            int val = p.second, num = p.first;
            bucket[val].push_back(num);
        }
        
        vector<int> ans;
        for(int i = nums.size(); k; i--)
        {
            for(auto a: bucket[i])
            {
                ans.push_back(a);
                k--;
            }
        }
        return ans;        
    }
};