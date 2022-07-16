class Solution {
public:
    int n,m, dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0}, mod = 1e9+7;
    int dp[55][55][55];
    bool valid(int x, int y)
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
    int dfs(int x, int y, int remMoves)
    {
        if(!valid(x,y)) return 1;
        if(remMoves <= 0) return 0;
        if(dp[x][y][remMoves] != -1) return dp[x][y][remMoves];
        
        int ans = 0;
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            ans = (ans%mod + (dfs(nx, ny, remMoves-1)%mod))%mod;
        }
        return dp[x][y][remMoves] = ans%mod;
    }
    int findPaths(int a, int b, int maxMove, int startRow, int startColumn) {
        n = a, m = b;
        memset(dp, -1, sizeof dp);
        return dfs(startRow, startColumn, maxMove)%mod;
    }
};