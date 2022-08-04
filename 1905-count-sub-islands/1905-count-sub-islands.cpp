class Solution {
public:
    int dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0},ans = 0,n,m;
    vector<vector<int>> g, g2;
    bool ok = 1;
    bool valid(int x, int y)
    {
        return x>=0 && x<n && y>=0 && y<m; 
    }
    void dfs(int x, int y)
    {
        if(g2[x][y] == 0) ok = 0;
        g[x][y] = 0;   
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(valid(nx, ny) && g[nx][ny] == 1)
            {
                dfs(nx, ny);
            }
        }            
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();
        g2 = grid1 , g = grid2;        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(g[i][j] == 1)
                {
                    dfs(i,j);
                    if(ok) ans++;
                    else ok = 1;
                }
            }
        }           
        return ans;        
    }
    
};