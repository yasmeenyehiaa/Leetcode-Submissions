class Solution {
public:
    int clr[10005];
    vector<int> ans;
    bool dfs(int src, vector<vector<int>>& graph)
    {
        if(clr[src]) return clr[src]==2;
        
        clr[src] = 1;
        for(auto a: graph[src])
        {
            if(clr[a] == 1 || !dfs(a, graph)) return 0;
        }
        clr[src] = 2;
        return true;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i=0; i<n; i++)
        {
            if(dfs(i,graph)) ans.push_back(i);
        }
        return ans;
        
    }
};