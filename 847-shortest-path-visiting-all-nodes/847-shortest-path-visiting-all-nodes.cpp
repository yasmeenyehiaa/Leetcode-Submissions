class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {        
        set<pair<int, int>> st;
        int lst = (1 << graph.size()) - 1;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < graph.size(); i++)
        {
            q.push(make_pair(i, (1<<i)));
            st.insert(make_pair(i, (1<<i)));
        }
        int ans = -1;
        
        while(!q.empty())
        {
            int sz = q.size();
            ans++;
            for(int i = 1; i <= sz; i++)
            {
                auto p = q.front();
                q.pop();
                
                if(p.second == lst) return ans;
                
                for(int i = 0; i < graph[p.first].size(); i++)
                {
                    if(st.find(make_pair(graph[p.first][i], p.second | (1 << graph[p.first][i]))) == st.end())
                    {
                        q.push(make_pair(graph[p.first][i], p.second | (1 << graph[p.first][i])));
                        st.insert(make_pair(graph[p.first][i], p.second | (1 << graph[p.first][i])));
                    }
                    
                }
            }
        }
        return -1;
    }
};