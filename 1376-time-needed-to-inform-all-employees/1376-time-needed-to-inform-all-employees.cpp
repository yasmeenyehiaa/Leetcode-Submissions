class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        queue<pair<int,int>> q;
        q.push({headID,0});
        vector<int> adj[n];
        for(int i=0; i<n; i++)
        {
            if(manager[i] == -1) continue;
            adj[manager[i]].push_back(i);
        }        
        int ans = 0;
        while(!q.empty())
        {
            int x = q.size();
            for(int i=0; i<x; i++)
            {
                int node = q.front().first, t = q.front().second;
                q.pop();
                for(auto a: adj[node])
                { 
                    int tt = t + informTime[node];
                    ans = max(ans, tt);
                    q.push({a, tt});
                }         
            }
        }       
        return ans;        
    }
};