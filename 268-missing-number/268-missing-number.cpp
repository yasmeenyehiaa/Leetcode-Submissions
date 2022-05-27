class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int vis[10005] = {0};
        for(int i=0; i<n; i++)
        {
            vis[nums[i]] = 1;
        }
        for(int i=0; i<=n; i++)
        {
            if(vis[i] == 0)
            {
                return i;
            }
        }
        return n;
        
    }
};