class Solution {
public:
    bool col[105], vis[105], ok = 1;
    void dfs(int src, bool c, vector<vector<int>>& graph)
    {
        vis[src] = 1;
        col[src] = c;
        for(auto a: graph[src])
        {
            if(!vis[a]) dfs(a, !c, graph);
            else if(c == col[a]) ok = 0;
        }
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        for(int i=0; i<graph.size(); i++)
        {
            if(!vis[i])  dfs(i,0, graph);
        }
        return ok;
    }
};