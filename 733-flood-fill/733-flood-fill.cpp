class Solution {
public:
    int c, o, n, m, dx[4] = {0,1,-1,0} , dy[4] = {1,0,0,-1};
    bool valid(int x, int y)
    {
        return x>=0 && x<n && y>=0 && y<m;
    }
    void dfs(vector<vector<int>>& image, int x, int y)
    {
        image[x][y] = c;
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(valid(nx, ny) && image[nx][ny] == o)
            {
                dfs(image, nx, ny);
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        c = color, o = image[sr][sc], n = image.size(), m = image[0].size();
        if(c!=o) dfs(image, sr, sc);
        
        return image;
    }
};