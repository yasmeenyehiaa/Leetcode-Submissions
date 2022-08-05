class Solution {
public:
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        queue<pair<int,int>> q;        
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }        
        while(!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nx= x+dx[i], ny = y+dy[i];
                if(nx>=0 && nx<n && ny >=0 && ny < m)
                {
                    if(dist[nx][ny] > dist[x][y]+1)
                    {
                        dist[nx][ny] = dist[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }        
        return dist;
    }
};