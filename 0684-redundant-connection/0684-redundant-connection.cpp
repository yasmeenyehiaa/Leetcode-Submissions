class Solution {
public:
    int par[1005], sz[1005];
    void Union(int a, int b)
    {
        a = par[a];
        b = par[b];
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a,b);
        par[a] = b;
        sz[b] += sz[a];
    }
    int Find(int a)
    {
        if(a == par[a]) return a;
        return par[a] = Find(par[a]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> ans = {0,0};
        int n = edges.size();
        for(int i=1; i<=n; i++) 
        {
            par[i] = i;
            sz[i] = 1;
        }
        for(auto edge: edges)
        {
            if(Find(edge[0]) == Find(edge[1]))
            {
                ans[0] = edge[0];
                ans[1] = edge[1];
            }
            Union(edge[0], edge[1]);
        }
        return ans;        
    }
};