class Solution {
public:
    map<string, vector<pair<string, double>>> graph;
    double dfs(string a, string b, map<string, int> &vis)
    {
        if(graph.find(a) == graph.end()) return -1;
        if(a == b) return 1;
        
        for(auto node: graph[a])
        {
            if(vis[node.first] == 1) continue;
            vis[node.first] = 1;
            double ans = dfs(node.first, b, vis);
            if(ans != -1) return ans * node.second;
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        for(int i=0; i<n; i++)
        {
            string a = equations[i][0], b = equations[i][1];
            double cost = values[i];
            
            graph[a].push_back({b, cost});
            graph[b].push_back({a, (double)1/cost});
        }
        
        vector<double> ans;
        for(int i=0; i<queries.size(); i++)
        {   
            map<string, int> vis;
            ans.push_back(dfs(queries[i][0], queries[i][1], vis));
        }
        return ans;
    }
};