class Solution {
public:
    int n,m, ctr, dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    vector<vector<char>> g;
    bool valid(int x, int y)
    {
        return (x<n && x>=0 && y>=0 && y<m);
    }
    void dfs(int x, int y)
    {
        g[x][y] = '0';
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(valid(nx,ny) && g[nx][ny] == '1')
            {
                dfs(nx,ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {        
        g = grid;
        n = g.size(), m = g[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(g[i][j] == '1') 
                {
                    ctr++;
                    dfs(i,j);
                }
            }
        }
        return ctr;
    }
};