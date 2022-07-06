class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int ctr = 0, n = rooms.size();
        queue<int> q;
        bool vis[1005] = {0};
        q.push(0);
        vis[0] = 1;
        while(q.size() != 0)
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
        for(int i=0; i<=n; i++)
        {
            if(vis[i]) 
            {
                ctr++;
                cout << i << " ";
            }
        }
        return ctr == n;
    }
};