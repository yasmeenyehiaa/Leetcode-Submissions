class Solution {
public:
    vector<int> c;
    int dp[1005], n;
    int solve(int idx)
    {
        if(idx >= n) {
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = min(solve(idx+1), solve(idx+2)) + c[idx]; 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof dp);
        n = cost.size();
        c = cost;
        return min(solve(0), solve(1));
    }
};