class Solution {
    vector<int> houses;
    vector<vector<int>> cost;
    int M, N, T, inf = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int solve(int i, int last, int cnt) {
        if (cnt > T) return inf;
        if (i == M) return cnt == T ? 0 : inf;
        if (dp[i][last][cnt] != -1) return dp[i][last][cnt];
        
        if (houses[i]) 
            return dp[i][last][cnt] = solve(i + 1, houses[i], houses[i] == last ? cnt : (cnt + 1));
        
        int ans = inf;
        for (int j = 0; j < N; ++j) 
        {
            ans = min(ans, cost[i][j] + solve(i + 1, j + 1, j + 1 == last ? cnt : (cnt + 1)));
        }
        return dp[i][last][cnt] = ans;
    }
public:
    int minCost(vector<int>& h, vector<vector<int>>& cst, int m, int n, int target) {
        houses = h, cost = cst, M = m, N = n, T = target;
        dp.assign(M, vector<vector<int>>(N + 1, vector<int>(T + 1, -1)));
        int ans = solve(0, 0, 0);
        return ans == inf ? -1 : ans;
    }
};