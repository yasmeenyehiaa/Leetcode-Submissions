class Solution {
public:
    int dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0},ans = 0,n,m;
    bool ok = 1;
    bool valid(int x, int y) {return x>=0 && x<n && y>=0 && y<m;} 
    void dfs(int x, int y, vector<vector<int>> & g, vector<vector<int>>& g2)
    {
        if(g2[x][y] == 0) ok = 0;
        g[x][y] = 0;   
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(valid(nx, ny) && g[nx][ny] == 1)
            {
                dfs(nx, ny, g, g2);
            }
        }            
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();     
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid2[i][j] == 1)
                {
                    dfs(i,j, grid2, grid1);
                    if(ok) ans++;
                    else ok = 1;
                }
            }
        }           
        return ans;        
    }
    
};