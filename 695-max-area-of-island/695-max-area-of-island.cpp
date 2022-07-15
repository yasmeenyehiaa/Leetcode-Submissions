class Solution {
public:
    vector<vector<int>> v;
    int n,m,ans, dx[4]={0,0,1,-1}, dy[4]={-1,1,0,0};
    bool valid(int x, int y)
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
    int dfs(int x, int y)
    {
        if(v[x][y] == 0) return 0;
        int ret = 1;
        v[x][y] = 0;
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(valid(nx, ny) && v[nx][ny])
            {
                ret += dfs(nx, ny);
            }
        }
        return ret;    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        v = grid;
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j])
                {
                    int x = dfs(i,j);
                    ans = max(ans, x);
                }
            }
        }
        return ans;
    }
};