class Solution {
public:
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
     int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
          int m = maze.size(), n = maze[0].size();
          queue<pair<pair<int,int>, int>>q;
          q.push({{entrance[0], entrance[1]}, 0});
         
         while(!q.empty())
          {
            int x = q.front().first.first, y = q.front().first.second, dist = q.front().second;
            q.pop();
             
            if(x<0 || y<0 || x>=m || y>=n || maze[x][y] == '+') continue;
            
            maze[x][y] = '+';
            if((x == 0 || y == 0 || x == m-1 || y == n-1) && !(x == entrance[0] && y == entrance[1]))
              return dist;
            
             for(int i=0; i<4; i++)
              q.push({{x+dx[i], y+dy[i]}, dist+1});
          }
          return -1;
    }
};