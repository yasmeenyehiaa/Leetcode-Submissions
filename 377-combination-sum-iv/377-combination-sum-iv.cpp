class Solution {
public:
    int dp[205][1005];
    vector<int> v;
    int solve(int i, int rem)
    {
        if(i == v.size() || rem == 0) return rem == 0;
        if(dp[i][rem] != -1) return dp[i][rem];
        
        int op1 = 0, op2 = 0;
        
        if(v[i] <= rem) op1 = solve(0, rem-v[i]);
        op2 = max(op2, solve(i+1, rem));
        
        return dp[i][rem] = op1 + op2;
    }
    int combinationSum4(vector<int>& nums, int t) {
        memset(dp, -1, sizeof dp);
        v = nums;
        return solve(0, t);
    }
};