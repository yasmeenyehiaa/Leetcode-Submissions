class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) { 
        vector<int> adj[n+2];
        int ans = 0;
        for(auto p: roads)
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end())
                {
                    ans = max(ans, int(adj[i].size()+adj[j].size()-1));
                }
                else ans = max(ans, int(adj[i].size()+adj[j].size()));
            }
        }
        return ans;
    }
};