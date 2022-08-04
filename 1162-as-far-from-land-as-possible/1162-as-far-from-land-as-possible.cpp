class Solution {
public:
    int dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0},n, ans = -1;
    bool valid(int x, int y) {
        return x>=0 && x<n && y>=0 && y<n;
    } 
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                }
            }
        }        
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                
                for(int j=0; j<4; j++)
                {
                    int nx = x+dx[j], ny= y+dy[j];
                    if(valid(nx,ny) && grid[nx][ny] == 0)
                    {
                        q.push({nx,ny});
                        grid[nx][ny] = 1;
                    }
                }
            }            
        }        
        return ans>0 ? ans: -1; 
    }
};