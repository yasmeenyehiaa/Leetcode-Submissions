class Solution {
public:
    int dx[8] = {-1,1,0,0,-1, 1, -1, 1}, dy[8] = {0,0,-1,1, 1, 1, -1, -1}, n;
    bool valid(int x, int y)
    {
        return (x<n && y<n && x>=0 && y>=0);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0] == 1) return -1;
        if(n == 1) return 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int ans = 1;
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int j=0; j<8; j++)
                {
                    int nx = x+dx[j], ny = y+dy[j];
                    if(valid(nx,ny) && grid[nx][ny] == 0)
                    {
                        q.push({nx,ny});
                        grid[nx][ny] = 1;
                        if(nx == n-1 && ny == n-1) return ans;
                    }
                   
                }
            }
        }
        return -1;
    }
};