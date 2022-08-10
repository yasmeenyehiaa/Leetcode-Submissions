class Solution {

    void bfs(vector<pair<int, int>> graph[], int start, int n, vector<int>& distance){

        queue<pair<int, pair<int,int>> > queue;
        distance[start] = 0;

        queue.push({0,{start,-1}});
        while(!queue.empty())
        {

            int uDist = queue.front().first;
            int u = queue.front().second.first;
            char uColor = queue.front().second.second;
            queue.pop();

            for(auto& it: graph[u])
            {
                int v = it.first;
                char vcolor = it.second;

                if(uColor != vcolor && vcolor != -1)
                {                    
                    if(distance[v] > uDist + 1) distance[v] = uDist + 1;
                    
                    queue.push({uDist+1, {v,vcolor}});
                    it.second = -1;
                }
            }
        }

        for(auto& a: distance)
            if(a == INT_MAX)
                a = -1;
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        vector<pair<int,int>> graph[n];

        for(auto edge: red_edges)
        {
            int u = edge[0], v = edge[1];
            graph[u].push_back({v,1});
        }

        for(auto edge: blue_edges)
        {
            int u = edge[0], v = edge[1];
            graph[u].push_back({v,0});
        }

        vector<int> ans(n,INT_MAX);
        bfs(graph, 0, n, ans);
        return ans;
    }
};