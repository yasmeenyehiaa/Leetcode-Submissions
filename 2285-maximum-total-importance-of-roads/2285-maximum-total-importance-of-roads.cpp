class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        long long ans = 0, val = n;
        vector<vector<int>> graph(n);
        for(int i=0; i<roads.size(); i++)
        {
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        priority_queue<int> pq;
        for(int i=0; i<n; i++)
        {
            pq.push(graph[i].size());
        }
        while(!pq.empty())
        {
            ans += (val * pq.top());
            pq.pop();
            --val;
        }
        return ans;
    }
};