class Solution {
public:
    bool vis[205];
    vector<int> adj[205];
    void dfs(int src)
    {
        vis[src] = 1;
        for(auto a: adj[src])
        {
            if(!vis[a]) dfs(a);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int ans = 0, n = isConnected.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j])
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                ans++; 
                dfs(i);
            }
        }
        return ans;        
    }
};