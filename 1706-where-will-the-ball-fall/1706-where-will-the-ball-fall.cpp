class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        vector<int> ans(grid[0].size());
        for(int c=0; c<grid[0].size(); c++)
        {
            int curCol = c;
            for(int r=0; r<grid.size(); r++)
            {
                int nxtCol = curCol + grid[r][curCol];
                if(nxtCol < 0 || nxtCol >= grid[0].size() || grid[r][curCol] != grid[r][nxtCol])
                {
                    ans[c] = -1;
                    break;
                }
                ans[c] = nxtCol;
                curCol = nxtCol;
                
            }
        }
        return ans;
    }
};