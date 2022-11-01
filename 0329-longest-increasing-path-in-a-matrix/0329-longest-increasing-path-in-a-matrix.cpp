class Solution {
public:
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    int dp[205][205],n ,m;
    bool check(int x, int y)
    {
        return (x>=0 && y>=0 && y<m && x<n);
    }
    int dfs(int x, int y, vector<vector<int>> &matrix)
    {
        if(dp[x][y] != 0) return dp[x][y];
        int ans = 1;
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(check(nx, ny) && matrix[nx][ny] < matrix[x][y])
            {
                ans = max(ans, 1+dfs(nx, ny, matrix));
            }
        }
        return dp[x][y] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        n = matrix.size(), m = matrix[0].size();
        int mx = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(dp[i][j] == 0) mx = max(mx, dfs(i,j, matrix));
            }
        }
        return mx;
    }
};