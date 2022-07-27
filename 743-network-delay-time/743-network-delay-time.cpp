class Solution {
public:
    int dis[105];
    vector<pair<int,int>> adj[105];
    void dijkstra(int src, int n)
    {
        for(int i=1; i<=n; i++)
        {
            dis[i] = 1e9;
        }
        priority_queue<pair<int,int>> pq;
        pq.push({0, src});
        dis[src] = 0;
        while(!pq.empty())
        {
            int d = -pq.top().first , u = pq.top().second;
            pq.pop();
            if(d != dis[u]) continue;
            for(auto a: adj[u])
            {
                int v = a.first, c = a.second;
                if(dis[u] + c < dis[v])
                {
                    dis[v] = dis[u]+c;
                    pq.push({-dis[v], v});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto el: times)
        {
            int u = el[0], v = el[1], c = el[2];
            adj[u].push_back({v,c});
            //adj[v].push_back({u,c});
        }
        dijkstra(k, n);
        int ans = 0, ctr = 1;
        for(int i=1; i<=n; i++)
        {
            if(i == k) continue;
            if(dis[i] < 1e9) 
            {
                ctr++;
                ans = max(ans, dis[i]);
            }
        }
        if(ctr != n) return -1;
        return ans;
    }
};