class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        map<int,int> indegree;
        queue<int> leaves;
        vector<vector<int>> graph(n);
        vector<int> ans;
        if(n == 1)
        {
            ans.push_back(0);
            return ans;
        }
        for(auto p: edges)
        {
            indegree[p[0]]++;
            indegree[p[1]]++;
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 1)
            {
                leaves.push(i);
                indegree[i]--;
            }
        }
        while(!leaves.empty())
        {
            ans.clear();
            int sz = leaves.size();
            for(int i=0; i<sz; i++)
            {
                int node = leaves.front();
                leaves.pop();
                ans.push_back(node);
                for(auto ch: graph[node])
                {
                    indegree[ch]--;
                    if(indegree[ch] == 1) leaves.push(ch);
                }
            }
        }
        return ans;
    }
};