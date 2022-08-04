class Solution {
public:
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0}, ans = 0, n,m;
    vector<vector<int>> g;
    bool valid(int x, int y)
    {
        return x>=0 && x<n && y>=0 && y<m; 
    }
    int dfs(int x, int y)
    {
        if(g[x][y] == 0) return 0;
        g[x][y] = 0;
        int ret = 1;
        
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(valid(nx, ny))
            {
                ret += dfs(nx, ny);
            }
            else ret += 1e7;
        }
        
        return ret;
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        n = grid.size(), m = grid[0].size();
        g = grid;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(g[i][j] == 1)
                {
                    int c = dfs(i,j);
                    if(c < 1e7) ans += c;
                }
            }
        }
        
        return ans;
    }
};