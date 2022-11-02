class Solution {
public:
    
    int dfs(int src, vector<vector<int>> &graph, vector<bool> &vis)
    {
        if(vis[src]) return 0;
        vis[src] = 1;
        int ans = 1;
        for(auto node: graph[src])
        {
            if(vis[node] == true) continue;
            ans += dfs(node, graph, vis);
        }
        return ans;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<bool> vis(n, 0);
        vector<vector<int>> graph(n);
        for(auto edge: edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(auto node: restricted)
        {
            vis[node] = 1;
        }
        return dfs(0, graph, vis);
    }
};