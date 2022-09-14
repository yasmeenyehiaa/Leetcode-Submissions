class Solution {
public:
    int dp[25][20005], t = 0;
    int solve(int i, int tot, const vector<int> &num, int sum)
      {
        if(i == num.size()) return tot == sum;
        if(dp[i][tot+t] != -1) return dp[i][tot+t];
        int ans = 0;
        ans += solve(i+1, tot+num[i], num, sum);
        ans += solve(i+1, tot-num[i], num, sum);      
        return dp[i][t+tot] = ans;
      }
    int findTargetSumWays(vector<int>& nums, int target) {
        for(auto el: nums) t += el;
        memset(dp, -1, sizeof dp);
        return solve(0, 0, nums, target);        
    }
};