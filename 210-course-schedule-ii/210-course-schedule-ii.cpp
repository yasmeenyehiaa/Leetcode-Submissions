class Solution {
public:
    bool vis[2005], stak[2005];
    vector<int> pre;
    vector<int> adj[2005];
    bool isCyclic(int src)
    {
        vis[src] = 1;
        stak[src] = 1;
        for(auto a: adj[src])
        {
            if(!vis[a]) 
            {
                if(isCyclic(a)) return true;
            }
            else if(stak[a]) return true;
        }
        pre.push_back(src);
        stak[src] = 0;
        return false;        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(auto v: prerequisites) adj[v[1]].push_back(v[0]);
        for(int i=0; i<numCourses; i++)
        {
            if(!vis[i])
            {
                if(isCyclic(i)) return {};
            }
        }
        reverse(pre.begin(), pre.end());
        return pre;
    }
};