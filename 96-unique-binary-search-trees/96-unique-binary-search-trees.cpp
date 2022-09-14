class Solution {
public:
    int dp[20];
    int solve(int n)
    {
        if(dp[n] != 0) return dp[n];
        for(int i=1; i<=n; i++)
        {
            int left = numTrees(i-1), right = numTrees(n-i);
            dp[n] += left*right;
        }
        return dp[n];
    }
    int numTrees(int n) {
        dp[0] = dp[1] = 1;
        return solve(n);
    }
};