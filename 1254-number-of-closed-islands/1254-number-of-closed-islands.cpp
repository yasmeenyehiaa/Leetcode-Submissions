class Solution {
public:
    int n,m,ctr;
    vector<vector<int>> g;
    bool valid(int x, int y)
    {
        return (x<n && x>=0 && y>=0 && y<m);
    }
    bool dfs(int x, int y)
    {
        if(g[x][y] == 1) return 1;
        g[x][y] = 1;
        bool bottom = valid(x+1, y) && dfs(x+1,  y);
        bool top = valid(x-1,y) && dfs(x-1,y);
        bool right = valid(x,y+1) && dfs(x,y+1);
        bool left = valid(x,y-1) && dfs(x,y-1);
        return (bottom && top && left && right);
    }
    int closedIsland(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(g[i][j] == 0)  ctr += dfs(i,j);
            }
        }
        return ctr;
    }
};