class Solution {
public:
    int n;
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle)
    {
        if(i==n || j== triangle[i].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int op1 = solve(i+1, j, dp, triangle);
        int op2 = solve(i+1, j+1, dp, triangle);
        return dp[i][j] = min(op1, op2) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {        
        n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(triangle.size(),-1));
        return solve(0, 0, dp, triangle);
    }
};