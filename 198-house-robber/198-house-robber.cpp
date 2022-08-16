class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int dp[101] = {0};
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i=2; i<n; i++)
        {
            dp[i] = dp[i-1];
            for(int j=0; j<=i-2; j++)
            {
                dp[i] = max(dp[j] + nums[i], dp[i]);
            }
        }
        return dp[n-1];
    }
};