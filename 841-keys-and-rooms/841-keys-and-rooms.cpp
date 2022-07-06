class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int ctr = 0, n = rooms.size();
        queue<int> q;
        q.push(0);  
        bool vis[1005] = {0};
        
        while(q.size())
        {
            int x = q.front();
            q.pop();
            vis[x] = 1;
            for(int i=0; i<rooms[x].size(); i++)
            {
                if(!vis[rooms[x][i]])
                {
                    //cout << rooms[x][i] << " ";
                    q.push(rooms[x][i]);
                }
            }
        }    
        
        for(int i=0; i<=n; i++) if(vis[i]) ctr++;
        
        return (ctr == n);
    }
};