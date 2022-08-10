class Solution {
public:
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0}, n, dn = 0;
    vector<vector<int>> g;
    vector<pair<int,int>> v1 , v2;
    bool valid(int x, int y)
    {
        return (x<n && y<n && x>=0 && y>=0);
    }
    void dfs(int x, int y)
    {
        if(dn) v2.push_back({x,y});
        else v1.push_back({x,y});
        g[x][y] = 0;
        
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(valid(nx,ny) && g[nx][ny] == 1) dfs(nx,ny);
        }
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(g[i][j] == 1) 
                {
                    dfs(i,j);
                    if(!dn) dn = 1;
                }
            }
        }
        int ans = 1e9;
        for(auto p1: v1)
        {
            for(auto p2: v2)
            {
                ans = min(ans, abs(p1.first-p2.first)+abs(p1.second-p2.second)-1);
            }
        }
        
        return ans;
    }
};