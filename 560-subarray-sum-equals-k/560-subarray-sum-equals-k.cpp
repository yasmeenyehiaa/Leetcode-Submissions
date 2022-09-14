class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans = 0, n = nums.size();
        unordered_map<int,int> mp;
        vector<int> prefix(n);
        prefix[0] = nums[0];
        mp[0] = 1;
        for(int i=1; i<n; i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
        }
        for(int i=0; i<n; i++)
        {
            if(mp.count(prefix[i]-k) != 0)
            {
                ans += mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};