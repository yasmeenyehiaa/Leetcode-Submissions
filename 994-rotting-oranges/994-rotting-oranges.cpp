class Solution {
public:
    int n,m, dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    bool valid(int x, int y)
    {
        return (x>=0 && y>=0 && y<m && x<n);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        n = grid.size(), m = grid[0].size();
        int c = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) c++;
            }
        }
        int ans = 0;
        if(!c) return ans;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int j=0; j<4; j++)
                {
                    int nx= x+dx[j], ny = y+dy[j];
                    if(valid(nx,ny) && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            ans++;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans-1;        
    }
};