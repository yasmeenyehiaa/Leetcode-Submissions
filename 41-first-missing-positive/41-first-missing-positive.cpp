class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size(), vis[500005] = {0};
        for(int i=0; i<n; i++)
        {
            if(nums[i] > 0 && nums[i] <= n)
            {
                vis[nums[i]]++;
            }
        }
        for(int i=1; i<=500001; i++)
        {
            if(!vis[i])
            {
                return i;
            }
        }
        return n+1;
        
    }
};