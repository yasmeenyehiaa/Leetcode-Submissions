class Solution {
public:
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0},n,m, P_ok, A_ok;
    int vis[205][205], id = 1;
    bool valid(int x, int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    void dfs(int x, int y, vector<vector<int>>& heights)
    {
        vis[x][y] = id;
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dy[i];
            if(valid(nx,ny) && vis[nx][ny] != id && heights[nx][ny] <= heights[x][y]) dfs(nx,ny,heights);
            else if(nx < 0 || ny < 0) P_ok = 1;
            else if(nx >= n || ny >= m) A_ok = 1;
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> ans;
        n = heights.size(), m = heights[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                //memset(vis, 0, sizeof vis);
                id++;
                P_ok = A_ok = 0;
                dfs(i,j,heights);
                if(P_ok && A_ok) 
                {
                    ans.push_back({i,j});
                }   
            }
        }
        return ans;
    }
};